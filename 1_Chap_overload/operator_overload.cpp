
#include <iostream>

using namespace std;

class Vector {
private :
	float x;
	float y;
	float z;

public :
	Vector(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	Vector operator+() const {
		return Vector( x, y, z);   // return *this;
	}
	Vector operator-() const {
		return Vector(-x, -y, -z);
	}
	Vector operator+(const Vector& v) const {
		return Vector(x + v.x, y + v.y, z + v.z);
	}
	Vector operator-(const Vector& v) const {
		return Vector(x - v.x, y - v.y, z - v.z);
	}
	float operator*(const Vector& v) const {
		return x * v.x + y * v.y + z * v.z;
	}
	Vector operator*(float v) const {
		return Vector(x * v, y * v, z * v);
	}
	Vector operator/(float v) const {
		return Vector(x / v, y / v, z / v);
	}
	Vector& operator++() {
		++x; ++y; ++z;
		return *this;
	}
	Vector& operator--() {
		--x; --y; --z;
		return *this;
	}
	Vector operator++(int) {
		Vector temp = *this;
		++(*this);
		return temp;
	}
	Vector operator--(int) {
		Vector temp = *this;
		--(*this);
		return temp;
	}

	friend Vector operator*(float v0, Vector& v1);	// friend function

	void print(int i) {
		cout << i << " : " << x << " " << y << " " << z << endl;
	}

};

Vector operator*(float v0, Vector& v1) {
	return Vector(v0 * v1.x, v0 * v1.y, v0 * v1.z);
};


int main() {

	const Vector v1(2, 4, 6);
	const Vector v2(3, 5, 7);

	Vector v3 = +v1;  		v3.print(3);
	Vector v4 = -v2;  		v4.print(4);
	Vector v5 = v1 + v2; 	v5.print(5);
	Vector v6 = v2 - v3;	v6.print(6);
	float  v7 = v1 * v2;	cout << " 7 : " << v7 << endl;
	Vector v8 = v1 * 3.f;	v8.print(8);
//	Vector v8 = v1.operator *(3.0f); v8.print(8);
	Vector v9 = v2 / 3.f;   v9.print(9);
	Vector v14 = 2.f * v3;	v14.print(14);
	Vector v10 = ++v3;		v10.print(10);
	Vector v11 = --v4;		v11.print(11);
	Vector v12 = v3++;		v12.print(12); v3.print(3);
	Vector v13 = v4--;		v13.print(13); v4.print(4);

	return EXIT_SUCCESS;
}

