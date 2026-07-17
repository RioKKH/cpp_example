// 生産者・消費者ハンドシェイクの最小例
// ビルド： gcc -o pc producer_consumer.c -pthread
// 実行： ./pc
// 共有メモリ + セマフォ2個による producer-consumer ハンドシェイクの最小例
// forkと匿名マッピング (MAP_ANONYMOUS) で親子プロセス間に共有領域を作成

#include <semaphore.h> // sem_*
#include <stdio.h>
#include <sys/mman.h> // mmap
#include <sys/wait.h> // wait
#include <unistd.h>

#define N 5 // やり直しする回数

// 親子プロセスで共有する領域
// 書く前に empty を待ち、書いたらfullを上げる。
// 読む前に full を待ち、読んだら empty を上げる。
// この両状態を往復が同期そのものとなる。
struct shared {
  sem_t empty; // 空きスロット数 (=書き込み可の合図)
  sem_t full;  // 中身の数       (=読み書き可の合図)
  int value;   // 1個分のバッファ
};

int main(void) {
  // 親子で共有するメモリを確保（匿名マッピング）
  struct shared *sh = mmap(NULL, sizeof *sh, PROT_READ | PROT_WRITE,
                           MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  // 第2引数 pshared = 1でプロセス間共有セマフォとして初期化
  sem_init(&sh->empty, 1, 1); // 最初は空きが1つ
  sem_init(&sh->full, 1, 0);  // 最初は中身が0

  if (fork() == 0) {
    // ----- consumer：消費者 (子プロセス) -----
    for (int i = 0; i < N; i++) {
      sem_wait(&sh->full); // 「中身あるよ」を待つ
      printf("  消費: %d\n", sh->value);
      sem_post(&sh->empty); // 「空けたよ」と合図
    }
    _exit(0);
  }

  // ----- producer：生産者 (親プロセス) -----
  for (int i = 0; i < N; i++) {
    sem_wait(&sh->empty); // 「空きあるよ」を待つ
    sh->value = i;
    printf("生産: %d\n", i);
    sem_post(&sh->full); // 「入れたよ」と合図
  }

  wait(NULL); // 子の終了を待つ
  sem_destroy(&sh->empty);
  sem_destroy(&sh->full);
  munmap(sh, sizeof *sh);
  return 0;
}
