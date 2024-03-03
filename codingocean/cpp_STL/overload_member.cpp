#include <iostream>
using namespace std;

struct VEC {
    float x, y;
    VEC operator*(const float& s) {
        return VEC{s*x , s*y};
    }

    VEC operator+(const VEC& rhs) {
        return VEC{x + rhs.x, y + rhs.y};
    }

    VEC operator-() {
        return VEC{-x, -y};
    }
    VEC operator++() {
        x += 1.0f;
        y += 1.0f;
        return *this;
        // return VEC{x, y};
    }
    VEC operator++(int) { // 後置きの場合は引数にintを入れる
        VEC tmp{x, y};
        x += 1; 
        y += 1;
        return tmp;
    }
};

//非メンバ関数
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

    vb = ++va; // ベクトルではこんなことしないが例として
    cout << va << vb;

    vb = va++; // 後置き
    cout << va << vb;

    return 0;
}
