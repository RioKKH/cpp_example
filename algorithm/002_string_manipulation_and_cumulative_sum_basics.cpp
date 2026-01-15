/**
 * 英小文字からなる文字列 S が与えられます。
 * S の中で、a と c がこの順で現れる箇所の
 * 組み合わせは何通りありますか？
 * つまり、i<j かつ S[i]=′a′ かつ S[j]=′c′ を
 * 満たすペア (i,j) の数を求めてください。
 * 制約:
 * S の長さは 1 以上 2×10^5 以下。
 *
 * 1回しかスキャン(線形スキャン)しないで全探索を行いたい。
 * これによって計算量を O(N) に落とすことが出来る！
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;

    long long ans = 0;
    long long a_count = 0;

    // 文字列を左から1文字ずつ確認する (O(N))
    for (int i = 1; i <= S.length(); i++)
    {
        if (S[i] == 'a')
        {
            // 'a'が出てきたらカウントを増やす
            a_count++;
        }
        else if (S[i] == 'c')
        {
            // 'c'が出てきたら、それより左にある'a'の数だけペアが出来る
            ans += a_count;
        }
    }
    cout << ans << endl;
    return 0;
}
