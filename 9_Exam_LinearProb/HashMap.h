
#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <iostream>
#include <vector>
#include <list>

const int TABLE_SIZE = 11;  			// Example table size
const int EMPTY = -1;					// Special marker for empty items
const std::string DELETED = "DELETED";	// Special marker for deleted items

template <typename K, typename V>
class Entry {							// a (key, value) pair
public:									// public functions
    Entry(const K& k = EMPTY, const V& v = "")			// constructor
      : _key(k), _value(v), _isDeleted(false) { }
    const K& key() const { return _key; }			// get key
    const V& value() const { return _value; }		// get value
    const bool isDelete() const { return _isDeleted; }
    void setKey(const K& k) { _key = k; }			// set key
    void setValue(const V& v) { _value = v; }		// set value
public:								// change private -> public data
    K _key;							// key
    V _value;						// value
    bool _isDeleted;
};

template <typename K, typename V>
class LinearProbHT {
public:										// public types
	friend class Entry<K,V>;
    typedef Entry<K,V> Entry;				// a (key,value) pair
private:
    std::vector<Entry> table;

    int hashFunction(const K& k) {
        return (3 * k + 5) % TABLE_SIZE;  	// Primary hash function
    }

public:										// public functions
    LinearProbHT() : table(TABLE_SIZE) {}	// constructor
    void put(const K& k, const V& v);		// insert/replace (k,v)
    void erase(const K& k);					// remove entry with key k
    const V& find(const K& k);				// find entry with key k
    void reinsert(const K& k, const V& v);  // reinsert (k,v)
    void display();
};



template <typename K, typename V>		// insert/replace (v,k)
void LinearProbHT<K,V>::put(const K& k, const V& v) {
    int index = hashFunction(k);
    int i = 0;

    while (table[index]._key != EMPTY && !table[index]._isDeleted && table[index]._key != k) {
        i++;
        index = (index + 1) % TABLE_SIZE;  // Linear probing

        if (i >= TABLE_SIZE) {  	// Prevent infinite loop if table is full
            std::cout << "Insertion Failed: Table Full\n";
            return;
        }
    }

    // Insert new entry
    table[index]._key = k;
    table[index]._value = v;
    table[index]._isDeleted = false;

}

template <typename K, typename V>		// remove entry with key k
void LinearProbHT<K,V>::erase(const K& k)  {
    int index = hashFunction(k);
    int i = 0;

    while (table[index]._key != EMPTY) {
        if (table[index]._key == k) {
            table[index]._key = EMPTY;
//            table[index]._value = DELETED;
            table[index]._value = "";
//            table[index]._isDeleted = true;
            table[index]._isDeleted = false;

            index = (index + 1) % TABLE_SIZE;
            while (table[index]._key != EMPTY) {
            	K k = table[index]._key;
            	V v = table[index]._value;
            	table[index]._key = EMPTY;
                reinsert(k, v);
                index = (index + 1) % TABLE_SIZE;
            }
            return;
        }
        i++;
        index = (index + 1) % TABLE_SIZE;

        if (i >= TABLE_SIZE) return;
    }

}

template <typename K, typename V>		// remove entry with key k
const V& LinearProbHT<K,V>::find(const K& k)  {
    int index = hashFunction(k);
    const std::string& errmsg = "Key not found";
    int i = 0;

    while (table[index]._key != EMPTY) {
        if (table[index]._key == k && !table[index]._isDeleted) {
            return table[index].value;
        }
        i++;
        index = (index + 1) % TABLE_SIZE;

        if (i >= TABLE_SIZE) break;
    }

    return errmsg;
}

template <typename K, typename V>		// reinsert entry with key k
void LinearProbHT<K,V>::reinsert(const K& k, const V& v) {
    int index = hashFunction(k);
    int i = 0;

    while (table[index]._key != EMPTY && !table[index]._isDeleted && table[index]._key != k) {
        i++;
        index = (index + 1) % TABLE_SIZE;  // Linear probing

        if (i >= TABLE_SIZE) {  	// Prevent infinite loop if table is full
            std::cout << "Insertion Failed: Table Full\n";
            return;
        }
    }

    // Insert new entry
    table[index]._key = k;
    table[index]._value = v;
    table[index]._isDeleted = false;

}

template <typename K, typename V>	// Print map contents
void LinearProbHT<K,V>::display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i]._key == EMPTY && !table[i]._isDeleted)
            std::cout << "[" << i << "] EMPTY" << std::endl;
        else
            std::cout << "[" << i << "] " << (table[i]._isDeleted ? DELETED : "(" + std::to_string(table[i]._key) + "," + table[i]._value + ")") << std::endl;
    }
}


#endif /* HASHMAP_H_ */
