#include <iostream>
using namespace std;

/**
 * 3つの整数 A,B,C と、目標となる値 K が与えられます。
 * 1 以上 A 以下の整数 a、1 以上 B 以下の整数 b、
 * 1 以上 C 以下の整数 c の組み合わせのうち、
 * a+b+c=K を満たすものは何通りありますか？
 * 制約:
 * 1≤A,B,C≤2000
 * 1≤K≤6000
 *
 * a + b + c = Kを満たすものはなん通り？
 * a, b, cを素直に３重ループすると、計算量がO(A x B x C)となる。
 * 2000^3 = 8,000,000,000 (80億) となり一般的な制限時間2秒に間に合わない。
 *
 * 効率的な2重ループで解くことを考える
 * 2重ループで全探索をすることを考える。
 */
int main()
{
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    long long count = 0;

    // aとbを全探索する (O(N^2))
    for (int a = 1; a <= A; a++)
    {
        for (int b = a; b <= B; b++)
        {
            // これが2重ループで全探索をするコツ
            // a + b + c = K => c = K - a - b
            int c = K - a - b;

            // cが1以上C以下であれば、条件を満たす組合せ
            if (c >= 1 && c <= C)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
