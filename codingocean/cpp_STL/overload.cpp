#include <iostream>
using namespace std;

struct VEC {
    float x, y;
};

// 非メンバ関数
// 演算子のオーバーロード
VEC operator*(const float& s, const VEC& v) {
    return VEC{s*v.x , s*v.y}; // C++20なら()でOK
}

VEC operator*(const VEC& v, const float& s) {
    return VEC{s*v.x , s*v.y}; // C++20なら()でOK
}

VEC operator+(const VEC& lhs, const VEC& rhs) {
    return VEC{lhs.x + rhs.x, lhs.y + rhs.y};
}

VEC operator-(const VEC& v) {
    return VEC{-v.x, -v.y};
}

ostream& operator<<(ostream& cOut, const VEC& v) {
    cOut << v.x << ", " << v.y << endl;
    return cOut;
}


int main()
{
    VEC v{1, 2};
    // v = 2.0f * v;
    v = v * 2.0f;
    cout << v.x << ", " << v.y << endl;

    VEC va{1, 2};
    VEC vb{3, 4};
    VEC vc = va + vb;
    cout << vc.x << ", " << vc.y << endl;

    vc = va + -vb;
    cout << vc.x << ", " << vc.y << endl;
    /// cout << vaがcOutになる。cout << vbがcOutになる。cout << vcがcOutになる。
    cout << va << vb << vc;

    return 0;
}
