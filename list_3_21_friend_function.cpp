#include <iostream>

class vector3d
{
	float x;
	float y;
	float z;

public:
	vector3d();
	explicit vector3d(float x, float y, float z);

	// フレンド関数の宣言
	// プロトタイプ宣言にfriendをつけただけ
	friend vector3d add(const vector3d& lhs, const vector3d& rhs);
	friend vector3d sub(const vector3d& lhs, const vector3d& rhs);

	void dump() const;
};

vector3d::vector3d() : vector3d(0, 0, 0)
{
}

vector3d::vector3d(float x, float y, float z)
	: x(x), y(y), z(z)
{
}

// 定義にはfrirendは不要
// 普通の関数の定義になっている。メンバー関数とは定義方法が異なる
vector3d add(const vector3d& lhs, const vector3d& rhs)
{
	vector3d result;
	// メンバー関数でないが非公開メンバーにアクセスすることができる
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;
	/**
	 * 以下のようにもかける
	 */
	// vector3d result = {
	// 	lhs.x - rhs.x,
	// 	lhs.y - rhs.y,
	// 	lhs.z - rhs.z
	// }
	return result;
}

vector3d sub(const vector3d& lhs, const vector3d& rhs)
{
	vector3d result;
	// メンバー関数出ないが非公開メンバーにアクセスすることができる
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;
	result.z = lhs.z - rhs.z;
	return result;
}

void vector3d::dump() const
{
	std::cout << x << ", " << y << ", " << z << std::endl;
}

int main()
{
	vector3d a(1, 1, 1), b(1, 2, 3);
	// フレンド関数はメンバー関数ではないので、普通の関数と同じ呼び出し方をする。
	vector3d c = add(a, b); // フレンド関数呼び出し
	vector3d d = sub(a, b);
	c.dump();
	d.dump();
}
