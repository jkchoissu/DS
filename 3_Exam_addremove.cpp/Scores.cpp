
#include <iostream>
#include <stdexcept>

using namespace std;

class IndexOutOfBounds {						// IndexOutOfBounds exception
public:
	IndexOutOfBounds(const string& err) 		// constructor
			: errMsg(err) { }
	string getError() { return errMsg; } 		// access error message
private:
	string errMsg; 								// error message
};

class GameEntry {							// a game score entry
public:
  GameEntry(const string& n="", int s=0);	// constructor
  string getName() const;					// get player name
  int getScore() const;						// get score
private:
  string name;								// player's name
  int score;								// player's score
};

GameEntry::GameEntry(const string& n, int s)	// constructor
  : name(n), score(s) { }
												// accessors
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

class Scores {									// stores game high scores
public:
  Scores(int maxEnt = 10);						// constructor
  ~Scores();									// destructor
  void add(const GameEntry& e);					// add a game entry
  GameEntry remove(int i)						// remove the ith entry
  	throw(IndexOutOfBounds);
  void display() const;
  int getentry() { return maxEntries; }
private:
  int maxEntries;								// maximum number of entries
  int numEntries;								// actual number of entries
  GameEntry* entries;							// array of game entries
};

Scores::Scores(int maxEnt) {					// constructor
  maxEntries = maxEnt;							// save the max size
  entries = new GameEntry[maxEntries];			// allocate array storage
  numEntries = 0;								// initially no elements
}

Scores::~Scores() {								// destructor
  delete[] entries;
}

void Scores::add(const GameEntry& e) {			// add a game entry
  if (numEntries < maxEntries) {				// the array is full
	  entries[numEntries] = e;
	  numEntries++;
  }
}

GameEntry Scores::remove(int i) throw(IndexOutOfBounds) {
  if ((i < 0) || (i >= numEntries))				// invalid index
    throw IndexOutOfBounds("Invalid index");
  GameEntry e = entries[i];						// save the removed object
  entries[i] = entries[numEntries-1];			// shift entries left
  numEntries--;									// one fewer entry
  return e;										// return the removed object
}

void Scores::display() const {
	cout << "Game Entry : " ;
	for ( int i = 0; i < numEntries; i++) {
		cout << "(" << entries[i].getName() << "," << entries[i].getScore() << ")";
	}
	cout << endl;
}

int main() {

	GameEntry g;
	Scores s;

	s.add(GameEntry("Anna", 660));
	s.display();
	s.add(GameEntry("Jack", 510));
	s.display();
	s.add(GameEntry("Mike", 1105));
	s.display();
	s.add(GameEntry("Paul", 720));
	s.display();
	s.add(GameEntry("Rob", 750));
	s.display();
	s.add(GameEntry("Rose", 590));
	s.display();
					// Add new object (Jill, 740) to the entries array
	s.add(GameEntry("Jill", 740));
	s.display();

	s.add(GameEntry("Tom", 600));
	s.display();

					// Removal of the entry at index 3 (Anna, 660)
	try {
		g = s.remove(3);
		cout << "(" << g.getName() << "," << g.getScore() << ")" << endl;
		s.display();
		s.remove(7);	// index invalid exception
		s.display();
	} catch (IndexOutOfBounds &e) {
		cerr << "Exception caught : " << e.getError() << endl;
	} catch (...) {
		cerr << "Unknown exception error " << endl;
	}

	return EXIT_SUCCESS;
}



