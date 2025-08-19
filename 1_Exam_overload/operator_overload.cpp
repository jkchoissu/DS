
#include <iostream>

using namespace std;

class Vector2 {
private :
	double x;
	double y;

public :
	Vector2(double _x, double _y) : x(_x), y(_y) {}
	Vector2 operator+() const {
		return Vector2( x, y);   // return *this;
	}
	Vector2 operator-() const {
		return Vector2(-x, -y);
	}
	Vector2 operator+(const Vector2& v) const {			// addition of two vectors
		return Vector2(x + v.x, y + v.y);
	}
	Vector2 operator-(const Vector2& v) const {			// subtraction of two vectors
		return Vector2(x - v.x, y - v.y);
	}
	double operator*(const Vector2& v) const {			// dot product of two vectors
		return x * v.x + y * v.y;
	}
	Vector2 operator*(float v) const {					// multiplication of a scalar times a vector
		return Vector2(x * v, y * v);
	}
	Vector2 operator/(float v) const {					// division of two vectors
		return Vector2(x / v, y / v);
	}
	Vector2& operator++() {								// pre-increment by 1
		++x; ++y;
		return *this;
	}
	Vector2& operator--() {								// pre-decrement by 1
		--x; --y;
		return *this;
	}
	Vector2 operator++(int) {							// post-increment by 1
		Vector2 temp = *this;
		++(*this);
		return temp;
	}
	Vector2 operator--(int) {							// post-decrement by 1
		Vector2 temp = *this;
		--(*this);
		return temp;
	}

	friend Vector2 operator*(float v0, Vector2& v1);	// friend function

	void print(int i) {
		cout << i << " :  (" << x << "," << y << ")" << endl;
	}

};


Vector2 operator*(float v0, Vector2& v1) {				// multiplication of a scalar times a vector
	return Vector2(v0 * v1.x, v0 * v1.y);
};

int main() {

	const Vector2 v1(2.2, 4.4);
	const Vector2 v2{3.3, 6.6};

	Vector2 v3 = +v1;  		v3.print(3);
	Vector2 v4 = -v2;  		v4.print(4);
	Vector2 v5 = v1 + v2; 	v5.print(5);
	Vector2 v6 = v2 - v3;	v6.print(6);
	float  v7 = v1 * v2;	cout << " 7 : " << v7 << endl;
	Vector2 v8 = v1 * 3.f;	v8.print(8);
	Vector2 v9 = v2 / 3.f;   v9.print(9);
	Vector2 v14 = 2.f * v3;	v14.print(14);
	Vector2 v10 = ++v3;		v10.print(10);
	Vector2 v11 = --v4;		v11.print(11);
	Vector2 v12 = v3++;		v12.print(12); v3.print(3);
	Vector2 v13 = v4--;		v13.print(13); v4.print(4);

	return EXIT_SUCCESS;
}

