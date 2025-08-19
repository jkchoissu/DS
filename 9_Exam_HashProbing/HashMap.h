
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
class ChainingHT {
public:										// public types
	friend class Entry<K,V>;
    typedef Entry<K,V> Entry;				// a (key,value) pair
private:
    std::vector<std::list<Entry>> table;  	// Separate chaining using lists

    int hashFunction(const K& k) {
        return (3 * k + 5) % TABLE_SIZE;  	// Primary hash function
    }

public:										// public functions
    ChainingHT() : table(TABLE_SIZE) {}	// constructor
    void put(const K& k, const V& v);	// insert/replace (k,v)
    void erase(const K& k);				// remove entry with key k
    const V& find(const K& k);			// find entry with key k
    void display();
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
    void display();
};

template <typename K, typename V>
class QuadraticProbHT {
public:										// public types
	friend class Entry<K,V>;
    typedef Entry<K,V> Entry;				// a (key,value) pair
private:
    std::vector<Entry> table;

    int hashFunction(const K& k) {
        return (3 * k + 5) % TABLE_SIZE;  	// Primary hash function
    }

public:										// public functions
    QuadraticProbHT() : table(TABLE_SIZE) {}	// constructor
    void put(const K& k, const V& v);			// insert/replace (k,v)
    void erase(const K& k);						// remove entry with key k
    const V& find(const K& k);					// find entry with key k
    void display();
};

template <typename K, typename V>
class DoubleHT {
public:									// public types
	friend class Entry<K,V>;
    typedef Entry<K,V> Entry;			// a (key,value) pair
private:
    std::vector<Entry> table;			// hash table

    int primaryHash(int key) {
        return (3 * key + 5) % TABLE_SIZE;  // Primary hash function
    }

    int secondaryHash(int key) {
        return 7 - (key % 7);  				// Secondary hash function
    }

public:									// public functions
    DoubleHT() : table(TABLE_SIZE) {}	// constructor
    void put(const K& k, const V& v);	// insert/replace (k,v)
    void erase(const K& k);				// remove entry with key k
    const V& find(const K& k);			// find entry with key k
    void display();
};


template <typename K, typename V>		// insert/replace (v,k)
void ChainingHT<K,V>::put(const K& k, const V& v) {
    int index = hashFunction(k);

    // Check if the key already exists, update value if found
    for (auto& entry : table[index]) {
        if (entry._key == k) {
            entry._value = v;
            return;
        }
    }

    // Insert new entry at the bucket index
    table[index].push_back(Entry(k, v));

}

template <typename K, typename V>		// remove entry with key k
void ChainingHT<K,V>::erase(const K& k)  {
    int index = hashFunction(k);

    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->_key == k) {
            table[index].erase(it);
            return;
        }
    }

}

template <typename K, typename V>		// remove entry with key k
const V& ChainingHT<K,V>::find(const K& k)  {
    int index = hashFunction(k);
    const std::string& errmsg = "Key not found";

    for (const auto& entry : table[index]) {
        if (entry._key == k) {
            return entry._value;
        }
    }

    return errmsg;
}

template <typename K, typename V>	// Print map contents
void ChainingHT<K,V>::display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        std::cout << "[" << i << "] ";
        for (const auto& entry : table[i]) {
            std::cout << "(" << entry._key << ": " << entry._value << ") -> ";
        }
        std::cout << "NULL\n";
    }
}

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
            table[index]._value = DELETED;
            table[index]._isDeleted = true;
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

template <typename K, typename V>	// Print map contents
void LinearProbHT<K,V>::display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i]._key == EMPTY && !table[i]._isDeleted)
            std::cout << "[" << i << "] EMPTY" << std::endl;
        else
            std::cout << "[" << i << "] " << (table[i]._isDeleted ? DELETED : "(" + std::to_string(table[i]._key) + "," + table[i]._value + ")") << std::endl;
    }
}


template <typename K, typename V>		// insert/replace (v,k)
void QuadraticProbHT<K,V>::put(const K& k, const V& v) {
    int index = hashFunction(k);
    int idx = index, i = 0;

    while (table[idx]._key != EMPTY && !table[idx]._isDeleted && table[idx]._key != k) {
        i++;
        idx = (index + i * i) % TABLE_SIZE;  // Quadratic probing

        if (i >= TABLE_SIZE) {  // Prevent infinite loop if table is full
            std::cout << "[Index : " << index << "] Insertion Failed: Table Full\n";
            return;
        }
    }

    // Insert new entry
    table[idx]._key = k;
    table[idx]._value = v;
    table[idx]._isDeleted = false;

}

template <typename K, typename V>		// remove entry with key k
void QuadraticProbHT<K,V>::erase(const K& k)  {
    int index = hashFunction(k);
    int idx = index, i = 0;

    while (table[idx]._key != EMPTY) {
        if (table[idx]._key == k) {
            table[idx]._key = EMPTY;
            table[idx]._value = DELETED;
            table[idx]._isDeleted = true;
            return;
        }
        i++;
        idx = (index + i * i) % TABLE_SIZE;

        if (i >= TABLE_SIZE) return;
    }
}

template <typename K, typename V>		// remove entry with key k
const V& QuadraticProbHT<K,V>::find(const K& k)  {
    int index = hashFunction(k);
    const std::string& errmsg = "Key not found";
    int idx = index, i = 0;

    while (table[idx]._key != EMPTY) {
        if (table[idx]._key == k && !table[idx]._isDeleted) {
            return table[idx]._value;
        }
        i++;
        idx = (index + i * i) % TABLE_SIZE;

        if (i >= TABLE_SIZE) break;
    }

    return errmsg;
}

template <typename K, typename V>	// Print map contents
void QuadraticProbHT<K,V>::display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i]._key == EMPTY && !table[i]._isDeleted)
            std::cout << "[" << i << "] EMPTY" << std::endl;
        else
            std::cout << "[" << i << "] " << (table[i]._isDeleted ? DELETED : "(" + std::to_string(table[i]._key) + "," + table[i]._value + ")") << std::endl;
    }
}

template <typename K, typename V>		// insert/replace (v,k)
void DoubleHT<K,V>::put(const K& k, const V& v) {
    int index = primaryHash(k);
    int step = secondaryHash(k);
    int idx = index, i = 0;

    while (table[idx]._key != EMPTY && !table[idx]._isDeleted && table[idx]._key != k) {
        i++;
        idx = (index + i * step) % TABLE_SIZE;  // Double hashing probe

        if (i >= TABLE_SIZE) {  // Prevent infinite loop if table is full
            std::cout << "Insertion Failed: Table Full\n";
            return;
        }
    }

    table[idx]._key = k;
    table[idx]._value = v;
    table[idx]._isDeleted = false;
}

template <typename K, typename V>		// remove entry with key k
void DoubleHT<K,V>::erase(const K& k)  {
    int index = primaryHash(k);
     int step = secondaryHash(k);
     int idx = index, i = 0;

     while (table[idx]._key != EMPTY) {
         if (table[idx]._key == k) {
             table[idx]._key = EMPTY;
             table[idx]._value = DELETED;
             table[idx]._isDeleted = true;
             return;
         }
         i++;
         idx = (index + i * step) % TABLE_SIZE;

         if (i >= TABLE_SIZE) return;
     }
}

template <typename K, typename V>		// remove entry with key k
const V& DoubleHT<K,V>::find(const K& k)  {
    int index = primaryHash(k);
    int step = secondaryHash(k);
    const std::string& errmsg = "Key not found";
    int idx = index, i = 0;

    while (table[idx]._key != EMPTY) {
        if (table[idx]._key == k && !table[idx]._isDeleted) {
            return table[idx]._value;
        }
        i++;
        idx = (index + i * step) % TABLE_SIZE;

        if (i >= TABLE_SIZE) break;
    }

    return errmsg;
}

template <typename K, typename V>	// Print map contents
void DoubleHT<K,V>::display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i]._key == EMPTY && !table[i]._isDeleted)
            std::cout << "[" << i << "] EMPTY" << std::endl;
        else
            std::cout << "[" << i << "] " << (table[i]._isDeleted ? DELETED : "(" + std::to_string(table[i]._key) + "," + table[i]._value + ")") << std::endl;
    }
}

#endif /* HASHMAP_H_ */
