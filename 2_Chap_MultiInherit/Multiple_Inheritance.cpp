
#include <iostream>

using namespace std;

class Base {
public :
	Base() : foo(1), bar(2), baz(3) {}
public :
	void print();
protected :
	int foo;
public :
	int bar;
private :
	int baz;
};

class Derive1 : public Base {		// public inheritance
	// foo is protected and bar is public
public :
	Derive1(int num) : Base(), deriveN(num) {}
	void updateD1() {
		foo = 11;
		bar = 12;
//		baz = 13;
	}
	void print();
private :
	int deriveN;
};

class Derive2 : protected Base {	// protected inheritance
	// both foo and bar are protected
public :
	Derive2(int num) : Base(), deriveN(num) {}
	void updateD2() {
		foo = 21;
		bar = 22;
//		baz = 23;
	}
	void print();
private :
	int deriveN;
};

class Derive3 : private Base {		// private inheritance
	// both foo and bar are private
public :
	Derive3(int num) : Base(), deriveN(num) {}
	void updateD3() {
		foo = 31;
		bar = 32;
//		baz = 33;
	}
	void print();
private :
	int deriveN;
};

void Base::print() {
	cout << " foo : " << Base::foo << endl;
	cout << " bar : " << Base::bar << endl;
	cout << " baz : " << Base::baz << endl;
}

void Derive1::print() {
	Base::print();
	cout << " Derived No. : " << Derive1::deriveN << endl;
}

void Derive2::print() {
	Base::print();
	cout << " Derived No. : " << Derive2::deriveN << endl;
}

void Derive3::print() {
	Base::print();
	cout << " Derived No. : " << Derive3::deriveN << endl;
}

int main() {

	Base b;
	Derive1 d1(1);
//	cout << " [1] foo : " << d1.foo << endl;
	cout << " [1] bar : " << d1.bar << endl;
//	cout << " [1] baz : " << d1.baz << endl;
	Derive2 d2(2);
//	cout << " [2] foo : " << d2.foo << endl;
//	cout << " [2] bar : " << d2.bar << endl;
//	cout << " [2] baz : " << d2.baz << endl;
	Derive3 d3(3);
//	cout << " [3] foo : " << d3.foo << endl;
//	cout << " [3] bar : " << d3.bar << endl;
//	cout << " [3] baz : " << d3.baz << endl;

	b.print();
	d1.updateD1();
	d1.print();
	d2.updateD2();
	d2.print();
	d3.updateD3();
	d3.print();

	return EXIT_SUCCESS;
}


