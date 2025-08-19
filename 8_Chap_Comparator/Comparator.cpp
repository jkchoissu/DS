
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Point2D {
public:
    Point2D(double x, double y) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }

    friend ostream& operator<<(ostream& os, const Point2D& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

private:
    double x, y;
};

template <typename E, typename C>		// element type and comparator
void printSmaller(const E& p, const E& q, const C& isLess) {
  cout << (isLess(p, q) ? p : q) << endl;	// print the smaller of p and q
}

class LeftRight {				// a left-right comparator
public:
  bool operator()(const Point2D& p, const Point2D& q) const
    { return p.getX() < q.getX(); }
};

class BottomTop {				// a bottom-top comparator
public:
  bool operator()(const Point2D& p, const Point2D& q) const
    { return p.getY() < q.getY(); }
};

int main() {

	priority_queue<Point2D, vector<Point2D>, LeftRight> p2;
	p2.push( Point2D(8.5, 4.6) );			// add three points to p2
	p2.push( Point2D(1.3, 5.7) );
	p2.push( Point2D(2.5, 0.6) );
	cout << p2.top() << endl;  p2.pop();	// output: (8.5, 4.6)
	cout << p2.top() << endl;  p2.pop();	// output: (2.5, 0.6)
	cout << p2.top() << endl;  p2.pop();	// output: (1.3, 5.7)

	Point2D p(1.3, 5.7), q(2.5, 0.6);		// two points
	LeftRight leftRight;					// a left-right comparator
	BottomTop bottomTop;					// a bottom-top comparator
	printSmaller(p, q, leftRight);			// outputs: (1.3, 5.7)
	printSmaller(p, q, bottomTop);			// outputs: (2.5, 0.6)

}
