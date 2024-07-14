#include <stdio.h>
#include <sys/types.h> // fork
#include <unistd.h>    // close, dup2, execlp, for, pipe

int main(int argc, char *argv[])
{
    int fd[2];
    pid_t pid;

    if (argc < 3)
    {
        fprintf(stderr, "%s command1 command2\n", argv[0]);
    }
    pipe(fd);
    if ((pid = fork()) == 0)
    { // 子プロセス
        // fdはパイプの読み口と書き口を指すファイルディスクリプタ
        // なので、子プロセスの標準出力1をパイプの書き口fd[1]につなぎ
        // 変える。
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        execlp(argv[1], argv[1], (char *)NULL);
    }
    else
    { // 親プロセス 
      // fdはパイプの読み口と書き口を指すファイルディスクリプタ
      // なので、親プロセスの標準入力0をパイプの読み口fd[0]につなぎ
      // 変える。
        dup2(fd[0], 0);
        close(fd[0]);
        close(fd[1]);
        execlp(argv[2], argv[2], (char *)NULL);
    }

    return 0;
}





