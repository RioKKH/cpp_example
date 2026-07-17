// 生産者・消費者ハンドシェイク (複数プロセス + ミューテックス +
// リングバッファ版) ビルド： gcc -o pc_multi producer_consumer_multi.c -pthread
// 実行： ./pc_multi
// 共有メモリ + セマフォ2個による producer-consumer ハンドシェイクの最小例
// forkと匿名マッピング (MAP_ANONYMOUS) で親子プロセス間に共有領域を作成

#include <pthread.h>   // pthread_mutex_*
#include <semaphore.h> // sem_*
#include <stdio.h>
#include <sys/mman.h> // mmap
#include <sys/wait.h> // wait
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 4 // リングバッファの容量
#define PROD 2 // 生産者の数
#define CONS 2 // 消費者の数
#define PER 5  // 生産者1つが作る個数(消費者1つが消費する個数も同じ)

/*
 * sem_init(&s, 1, v) : カウンタsの初期値をvにする
 * sem_wait(&s) : カウンタを1つ減らす。0の時は誰かが増やすまでブロックして待つ
 * sem_post(&s) : カウンタを1つ増やす
 */

// 親子プロセスで共有する領域
// 書く前に empty を待ち、書いたらfullを上げる。
// 読む前に full を待ち、読んだら empty を上げる。
// この両状態を往復が同期そのものとなる。
struct shared {
  sem_t empty;              // 空きスロット数 (=書き込み可の合図)
  sem_t full;               // 中身の数       (=読み書き可の合図)
  pthread_mutex_t mtx_head; // headを守るmutex (生産者同士の排他)
  pthread_mutex_t mtx_tail; // tailを守るmutex (消費者同士の排他)
  int buf[SIZE];            // リングバッファ本体
  int head;                 // 次に書き込む位置
  int tail;                 // 次に読み込む位置
};

int main(void) {
  // 親子で共有するメモリを確保（匿名マッピング）
  struct shared *sh = mmap(NULL, sizeof *sh, PROT_READ | PROT_WRITE,
                           MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  // 第2引数 pshared = 1でプロセス間共有セマフォとして初期化
  sem_init(&sh->empty, 1, SIZE); // 最初はSIZE個分空いている
  sem_init(&sh->full, 1, 0);     // 最初は中身が0
  sh->head = sh->tail = 0;

  // ミューテックスもプロセス間共有として初期化する
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
  pthread_mutex_init(&sh->mtx_head, &attr);
  pthread_mutex_init(&sh->mtx_tail, &attr);

  // ----- 生産者を PROD 個だけ fork する -----
  for (int p = 0; p < PROD; p++) {
    if (fork() == 0) {
      for (int i = 0; i < PER; i++) {
        int item = p * 100 + 1; // どの生産者かわかる値
        sem_wait(&sh->empty);

        pthread_mutex_lock(&sh->mtx_head);
        int idx = sh->head; // 書き込む位置を確保
        sh->head = (sh->head + 1) % SIZE;
        pthread_mutex_unlock(&sh->mtx_head);

        sh->buf[idx] = item; // 確保した位置は自分専用なので外に書いてよい
        printf("生産者%d -> %d\n", p, item);
        sem_post(&sh->full); // 中身を一つ増やす
      }
      _exit(0);
    }
  }

  // ----- 消費者を CONS 個だけ fork する -----
  for (int c = 0; c < CONS; c++) {
    if (fork() == 0) {
      for (int i = 0; i < PER; i++) {
        sem_wait(&sh->full); // 中身を一つ確保する

        pthread_mutex_lock(&sh->mtx_tail);
        int idx = sh->tail; // 読む位置を確保
        sh->tail = (sh->tail + 1) % SIZE;
        pthread_mutex_unlock(&sh->mtx_tail);

        int v = sh->buf[idx];
        printf("消費者%d <- %d\n", c, v);
        sem_post(&sh->empty);
      }
      _exit(0);
    }
  }

  for (int i = 0; i < PROD + CONS; i++) {
    wait(NULL); // 子の終了を待つ
  }

  pthread_mutex_destroy(&sh->mtx_head);
  pthread_mutex_destroy(&sh->mtx_tail);
  sem_destroy(&sh->empty);
  sem_destroy(&sh->full);
  munmap(sh, sizeof *sh);
  return 0;
}
