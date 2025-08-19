#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

class Shape {					// Abstract Base Class
public :
	virtual double getArea() const = 0;
};

class Circle : public Shape {	// Derived Class : Circle
private :
	double radius;
public :
	Circle(double r) : radius(r) {}
	double getArea() const override {
		return M_PI * radius * radius; // Area of a circle
	}
};

class Rectangle : public Shape {	// Derived Class : Rectangle
private :
	double width, height;
public :
	Rectangle(double w, double h) : width(w), height(h) {}
	double getArea() const override {
		return width * height;		// Area of a rectangle
	}
};

int main() {
	// Create objects of Circle and Rectangle
	Shape* circle = new Circle(5.0);
	Shape* rectangle = new Rectangle(4.0, 6.0);

	cout << " Area of a circle : " << circle->getArea() << endl;
	cout << " Area of a rectangle : " << rectangle->getArea() << endl;

	return EXIT_SUCCESS;
}
