#!/bin/bash

# pkg-configを使用してgtkmmのフラグを取得
CFLAGS=$(pkg-config gtkmm-3.0 --cflags)
LIBS=$(pkg-config gtkmm-3.0 --libs)

# .cclsファイルを作成
echo "clang" > .ccls
for i in $CFLAGS; do
    echo "$i" >> .ccls
done

for i in $LIBS; do
    echo "$i" >> .ccls
done
