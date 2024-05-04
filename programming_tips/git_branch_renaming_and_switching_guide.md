# Git

## ブランチの入れ替え

featureブランチ上での変更量が多くなり、featureブランチをマージするのではなく、mainブランチに置き換えたい時があります（そのような事をすることがgitのコントロール戦略として正しいのかはとりあえず脇に置いておくとして）。

そのような場合には以下のような手順で変更するとよいです。

1. 現在のリポジトリの状態を確認する。
   ```bash
   $ git branch
   ```

   ローカルブランチの状態を確認しておく。

2. `main`ブランチを`main_<date>`ブランチにリネームする
   先ず、`main`ブランチにスイッチします

   ```bash
   $ git switch main
   ```

   次に、`main`ブランチを`main_<date>`ブランチにリネームします
   ```bash
   $ git branch -m main main_<date>
   ```

   このコマンドを実行することで、ローカルには`main`ブランチが存在しなくなります。

3. `feature`ブランチを新しい`main`ブランチにする
   先ず、`feature`ブランチにスイッチします。

   ```bash
   $ git switch feature
   ```

   次に、`feature`ブランチを`main`ブランチにリネームします
   ```bash
   $ git branch -m feature main
   ```

   これでローカルからは`feature` ブランチが無くなり、代わりに`main`ブランチが誕生します。

4. リネームしたブランチをリモートにプッシュする
   先ず、新しい`main`ブランチをリモートにプッシュします

   ```bash
   $ git push origin main
   ```

   次に、`main_<date>`ブランチをリモートにプッシュします
   ```bash
   $ git push origin main_<date>
   ```

   最後に、リモートの不要になった`feature`ブランチを削除します。
   ```bash
   $ git push origin --delete feature
   ```

5. リモートの追跡ブランチを更新する
   ローカルのブランチがリモートのブランチを正しく追跡できるように設定します。

   ```bash
   $ git branch -u origin/main main
   $ git branch -u origin/main_<date> main_<date>
   ```

   