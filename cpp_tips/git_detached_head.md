# Git

## デタッチドヘッド (Detached head)

過去のコミットに一時的に切り替えたい場合に便利な方法

```bash
$ git switch --detach <commit-hash>
```

このコマンドはHEADを指定されたコミットに移動し、その状態でデタッチされたHEAD状態になる。これにより、現在のブランチから離れて、指定したコミットの状態で作業を行うことが出来る。過去のコードを一時的に試してみたい場合に便利。

図にすると以下の様になる。

```css
 A---B---C---D [master]
       \
        E---F---G [feature]
             \
              H [HEAD] (デタッチドHEAD状態)
```

元のブランチに戻るには、単にブランチ名で`git switch main`といった形で実行すればよい。



## 実行例

```bash
rio@ThinkPadP14s:~/work/git/EA/onemax/onemaxcpu$ git switch --detach 9f30d247e2124cc04bfc63069fbf1b33a66c
0aff
HEAD is now at 9f30d24  modified:   CUDAKernels.cu      modified:   CUDAKernels.h       modified:   Evolution.cu
rio@ThinkPadP14s:~/work/git/EA/onemax/onemaxcpu$ git branch -a
* (HEAD detached at 9f30d24)
  main
  rand123
  tunedEA
  tuned_swapPopulation
  remotes/origin/HEAD -> origin/main
  remotes/origin/main
  remotes/origin/param_regular
  remotes/origin/param_singleton
  remotes/origin/rand123
  remotes/origin/tunedEA
  remotes/origin/tuned_swapPopulation
```

元のブランチに戻してみる

```bash
rio@ThinkPadP14s:~/work/git/EA/onemax/onemaxcpu$ git switch main
Previous HEAD position was 9f30d24      modified:   CUDAKernels.cu      modified:   CUDAKernels.h       modified:   Evolution.cu
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
rio@ThinkPadP14s:~/work/git/EA/onemax/onemaxcpu$ git branch -a
  main
  rand123
  tunedEA
* tuned_swapPopulation
  remotes/origin/HEAD -> origin/main
  remotes/origin/main
  remotes/origin/param_regular
  remotes/origin/param_singleton
  remotes/origin/rand123
  remotes/origin/tunedEA
  remotes/origin/tuned_swapPopulation
```

ログを見ると確かにこれでHEADが指すのは最新のコミットになっている。