# nvim登録方法

### nvimをviとして登録する方法

```bash
sudo update-alternatives --install /usr/bin/vi vi /home/kakehi/bin/nvim0.10.0/AppRun 60
sudo update-alternatives --install /usr/bin/vim vim /home/kakehi/bin/nvim0.10.0/AppRun 60
```

### 設定確認方法

```bash
sudo update-alternatives --display vi
sudo update-alternatives --display vim
```

### 複数の選択肢から手動で選択する方法

```bash
sudo update-alternatives --config vi
sudo update-alternatives --config vim
```

