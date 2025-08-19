
#include <iostream>
#include <string>

using namespace std;

class Person { 			// Person (base class)
private:
	string name; 		// name
	string idNum; 		// university ID number
public:
	Person(const string& nm, const string& id); // constructor
	virtual ~Person() {} 						// virtual destructor for polymorphic behavior
//	void print();								// print information
	virtual void print(); 						// consider making print virtual as well
	string getName(); 	// retrieve name
};

class Student : public Person { 	// Student (derived from Person)
private:
	string major; 					// major subject
	int gradYear; 					// graduation year
public:
												// constructor
	Student(const string& nm, const string& id,	const string& maj, int year);
	~Student() {}
	void print() override; 						// print information
	void changeMajor(const string& newMajor); 	// change major
};

class Employee : public Person {	// Employee (derived from Person)
private :
	string department;				// department of the company
	string position;				// position in the company
public :
													// constructor
	Employee(const string& nm, const string& id, const string& depart, const string& pos);
	~Employee() {}
	void print() override;							// print information
	void getPromoted(const string& newPosition);	// get promoted at work
};

Person::Person(const string& nm, const string& id)
	: name(nm), 					// initialize name
	  idNum(id) { } 				// initialize ID number

void Person::print() { 				// definition of Person print
	cout << ">>>> Name " << name << " <<<<" << endl;
	cout << "IDnum " << idNum << endl;
}

string Person::getName() {
	return name;
}

Student::Student(const string& nm, const string& id,const string& maj, int year)
	: Person(nm, id), 		// initialize Person members
	  major(maj), 			// initialize major
	  gradYear(year) { } 	// initialize graduation year

void Student::print() { 	// definition of Student print
	Person::print(); 		// first print Person information
	cout << "Major " << major << endl;
	cout << "Year " << gradYear << endl;
}

Employee::Employee(const string& nm, const string& id, const string& depart, const string& pos)
	: Person(nm, id), 		// initialize Person members
	  department(depart), 	// initialize department
	  position(pos) { }		// initialize position

void Employee::print() { 	// definition of Employee print
	Person::print(); 		// first print Person information
	cout << "Department " << department << endl;
	cout << "Position " << position << endl;
}

void Student::changeMajor(const string& newMajor) {
	major = newMajor;
}

void Employee::getPromoted(const string& newPosition) {
	position = newPosition;
}

int main() {

	Person person("Mary", "12-345"); 		// declare a Person
	Student student("Bob", "98-764", "Math", 2012); // declare a Student

	cout << student.getName() << endl; 		// invokes Person::getName()
	person.print(); 						// invokes Person::print()
	student.print(); 						// invokes Student::print()
//	person.changeMajor("Physics"); 			// ERROR!
	student.changeMajor("English"); 		// okay
	student.print(); 						// invokes Student::print()

	cout << endl;

	Person* pp[100]; 							// array of 100 Person pointers
	pp[0] = new Person("Albert", "20250001"); 	// add a Person (details omitted)
	pp[1] = new Student("John", "20250002", "Computer", 2029);
												// add a Student (details omitted)
	pp[2] = new Employee("Peter", "2025003", "Software Development", "Director");
												// add an Employee (details omitted)
	cout << pp[1]->getName() << endl; 			// okay
	cout << pp[2]->getName() << endl; 			// okay
	pp[0]->print(); 							// calls Person::print()
	pp[1]->print(); 							// calls Person::print() (!)
												// calls Student::print() if "virtual" is added
	pp[2]->print(); 							// calls Person::print() (!)
												// calls Employee::print() if "virtual" is added
//	pp[1]->changeMajor("Chemstry"); 			// ERROR!
//	pp[2]->getPromoted("Vice President"); 		// ERROR!

	Student* sp = dynamic_cast<Student*>(pp[1]);	// cast pp[1] to Student*
	sp->changeMajor("Chemistry");					// now changeMajor is legel
	sp->print();

	Employee* ep = dynamic_cast<Employee*>(pp[2]);	// cast pp[2] to Employee*
	ep->getPromoted("Vice President");				// call Employee::getPromoted
	ep->print();									// calls Employee::print()

	return EXIT_SUCCESS;
}

