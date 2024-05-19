# Doxygen

### グローバル変数に関するコメント記述方法

```c
/**
 * @file example.c
 * @brief グローバル変数を用いたDoxygen記述方法の例
 * @date 2024/05/20
 */

/**
 * @var global_counter
 * @brief グローバルなカウンター変数
 *
 * 関数が実行されたトータルの回数をカウントするための
 * グローバル変数
 */
int global_counter = 0;

/**
 * @brief 2つの整数を足し合わせる関数
 *
 * @param[in] a 足し合わせる1つ目の整数
 * @param[in] b 足し合わせる2つ目の整数
 * @return 2つの整数値の合計値
 * @note この関数は グローバル変数である @ref global_counter を用いる
 */
int add (int a, int b) {
    global_counter++;
    return a + b;
}
```

