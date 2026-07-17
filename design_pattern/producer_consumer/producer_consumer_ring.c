// 生産者・消費者ハンドシェイク (複数プロセス + ミューテックス +
// リングバッファ版) ビルド： gcc -o pc_multi producer_consumer_multi.c -pthread
// 実行： ./pc_multi
// 共有メモリ + セマフォ2個による producer-consumer ハンドシェイクの最小例
// forkと匿名マッピング (MAP_ANONYMOUS) で親子プロセス間に共有領域を作成

#include <semaphore.h> // sem_*
#include <sys/mman.h>  // mmap
#include <sys/wait.h>  // wait
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 4 // リングバッファの容量
#define N 10   // やり取りする回数
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
  sem_t empty;   // 空きスロット数 (=書き込み可の合図)
  sem_t full;    // 中身の数       (=読み書き可の合図)
  int buf[SIZE]; // リングバッファ本体
  int head;      // 次に書き込む位置
  int tail;      // 次に読み込む位置
};

int main(void) {
  // 親子で共有するメモリを確保（匿名マッピング）
  struct shared *sh = mmap(NULL, sizeof *sh, PROT_READ | PROT_WRITE,
                           MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  // 第2引数 pshared = 1でプロセス間共有セマフォとして初期化
  sem_init(&sh->empty, 1, SIZE); // 最初はSIZE個分空いている
  sem_init(&sh->full, 1, 0);     // 最初は中身が0
  sh->head = sh->tail = 0;

  if (fork() == 0) {
    // ----- consumer：消費者 (子プロセス) -----
    for (int i = 0; i < N; i++) {
      sem_wait(&sh->full); // 「中身あるよ」を待つ
      int v = sh->buf[sh->tail];
      sh->tail = (sh->tail + 1) % SIZE; // 位置を進める（端で先頭に戻る）
      printf("  消費: %d\n", v);
      sem_post(&sh->empty); // 「空けたよ」と合図
    }
    _exit(0);
  }

  // ----- producer：生産者 (親プロセス) -----
  for (int i = 0; i < N; i++) {
    sem_wait(&sh->empty); // 「空きあるよ」を待つ
    sh->buf[sh->head] = i;
    sh->head = (sh->head + 1) % SIZE; // 位置を決める（端で先頭に戻る）
    printf("生産: %d\n", i);
    sem_post(&sh->full); // 「入れたよ」と合図
  }

  wait(NULL); // 子の終了を待つ
  sem_destroy(&sh->empty);
  sem_destroy(&sh->full);
  munmap(sh, sizeof *sh);
  return 0;
}
