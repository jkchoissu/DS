
#ifndef ENTRY_H_
#define ENTRY_H_

enum Color {RED, BLACK};				// node colors

template <typename K, typename V>
class Entry {				// a (key, value) pair
public:						// public types
    typedef K Key;			// key type
    typedef V Value;		// value type
public:						// public functions
    Entry(const K& k = K(), const V& v = V())		// constructor
      : _key(k), _value(v), col(BLACK) { }
    const K& key() const { return _key; }		// get key (read only)
    const V& value() const { return _value; }	// get value (read only)
    void setKey(const K& k) { _key = k; }		// set key
    void setValue(const V& v) { _value = v; }	// set value
    Color color() const { return col; }			// get color
    bool isRed() const { return col == RED; }
    bool isBlack() const { return col == BLACK; }
    void setColor(Color c) { col = c; }
private:						// private data
    K _key;						// key
    V _value;					// value
    Color col;					// node color
};

#endif /* ENTRY_H_ */
