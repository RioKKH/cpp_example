#include <sys/types.h> // fork, read, wait, write
#include <sys/uio.h>   // read, write uioは何の略？unix input output
#include <sys/wait.h>  // wait
#include <unistd.h>    // close, fork, pipe, read, write
#include <stdio.h>     // printf
#include <stdlib.h>    // exit
#include <errno.h>     // errno
#include <string.h>    // strerror

void error_exit(const char *msg)
{
    perror(msg);
    exit(1);
}

/* エラー処理を追加したpipe_fork_child2parent.c */
int main(void)
{
    int n, fd[2];
    char buf[1024];
    pid_t pid;

    if (pipe(fd) == -1)
    {
        error_exit("pipe");
    }
    // fd[0]: パイプの読み込み口を表すファイルディスクリプタ
    // fd[1]: パイプの書き込み口を表すファイルディスクリプタ
    if ((pid = fork()) == -1)
    {
        error_exit("fork");
    } 
    else if (pid == 0)
    { /* 子プロセス */
        /*
         * child --> parentにデータをおくるので、子プロセス側では
         * パイプの読み込み口が不要になる。そのためfd[0]をcloseする。
         * 同様に親プロセス側にデータを送るので、パイプの書き込み口に
         * writeする。したがってfd[1]を指定してwriteする。
         * 書き込み完了後は、パイプの書き込み口をcloseする。
         */
        if (close(fd[0]) == -1) error_exit("close");
        if (write(fd[1], "Hello\n", 6) != 6) error_exit("write");
        if (close(fd[1]) == -1) error_exit("close");
    }
    else
    { /* 親プロセス */
        if (close(fd[1]) == -1) error_exit("close");
        n = read(fd[0], buf, sizeof(buf));
        if (n == -1) error_exit("read");
        if (write(1, buf, n) != n) error_exit("write");
        if (close(fd[0]) == -1) error_exit("close");
        if (wait(NULL) == -1) error_exit("wait"); // 子プロセスの終了を待つ
    }
    return 0;
}





