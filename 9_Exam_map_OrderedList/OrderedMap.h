
#ifndef ORDEREDMAP_H_
#define ORDEREDMAP_H_

#include <iostream>

template <typename K, typename V>
class Entry {				// a (key, value) pair
public:						// public functions
    Entry(const K& k = K(), const V& v = V())		// constructor
      : _key(k), _value(v), prev(NULL), next(NULL) { }
    const K& key() const { return _key; }			// get key
    const V& value() const { return _value; }		// get value
    void setKey(const K& k) { _key = k; }			// set key
    void setValue(const V& v) { _value = v; }		// set value
private:							// private data
    K _key;							// key
    V _value;						// value
public:
    Entry* prev;
    Entry* next;
};

template <typename K, typename V>
class OrderedMap {
public:						// public types
    typedef Entry<const K,V> Entry;		// a (key,value) pair
private:
    Entry* head;					// bucket array
public:									// public functions
    OrderedMap() : head(NULL) { }		// constructor
    const V& find(const K& k);			// find entry with key k
    void put(const K& k, const V& v);	// insert/replace (k,v)
    void erase(const K& k);					// remove entry with key k
    void display();
};

template <typename K, typename V>		// find key
const V& OrderedMap<K,V>::find(const K& k) {
    Entry* current = head;
    const std::string& errmsg = "Key not found";

    while (current) {
        if (current->key() == k) return current->value();
        current = current->next;
    }
    return errmsg;
}

template <typename K, typename V>		// insert/replace (v,k)
void OrderedMap<K,V>::put(const K& k, const V& v) {
    Entry* newNode = new Entry(k, v);

    if (!head || k < head->key()) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        return;
    }

    Entry* current = head;
    while (current->next && current->next->key() < k) {
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next) current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
}

template <typename K, typename V>		// remove entry with key k
void OrderedMap<K,V>::erase(const K& k)  {
    Entry* current = head;
    while (current && current->key() != k) {
        current = current->next;
    }

    if (!current) return; // Key not found

    if (current->prev) current->prev->next = current->next;
    else head = current->next;

    if (current->next) current->next->prev = current->prev;

    delete current;
}


template <typename K, typename V>	// Print map contents
void OrderedMap<K,V>::display() {
    Entry* current = head;
    while (current) {
        std::cout << "(" << current->key() << ": " << current->value() << ") -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}


#endif /* ORDEREDMAP_H_ */
