/*
 * Map.h
 *
 *  Created on: 2025. 3. 1.
 *      Author: alber
 */

#ifndef MAP_H_
#define MAP_H_

  template <typename K, typename V>
  class Entry {						// a (key, value) pair
  public:						// public functions
    Entry(const K& k = K(), const V& v = V())		// constructor
      : _key(k), _value(v) { }
    const K& key() const { return _key; }		// get key
    const V& value() const { return _value; }		// get value
    void setKey(const K& k) { _key = k; }		// set key
    void setValue(const V& v) { _value = v; }		// set value
  private:						// private data
    K _key;						// key
    V _value;					// value
  };

  class Iterator {	                      		// an iterator (& position)
  private:
    EItor ent;					// which entry
    BItor bkt;					// which bucket
    const BktArray* ba;			// which bucket array
  public:
    Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())
      : ent(q), bkt(b), ba(&a) { }
    Entry& operator*() const;			// get entry
    bool operator==(const Iterator& p) const;		// are iterators equal?
    Iterator& operator++();				// advance to next entry
    friend class HashMap;				// give HashMap access
  };

  template <typename K, typename V>
  class Map {					// map interface
  public:
    class Entry;				// a (key,value) pair
    class Iterator;				// an iterator (and position)

    int size() const;				// number of entries in the map
    bool empty() const;				// is the map empty?
    Iterator find(const K& k) const;		// find entry with key k
    Iterator put(const K& k, const V& v);	// insert/replace pair (k,v)
    void erase(const K& k)			// remove entry with key k
      throw(NonexistentElement);
    void erase(const Iterator& p);	// erase entry at p
    Iterator begin();				// iterator to first entry
    Iterator end();					// iterator to end entry
  };


#endif /* MAP_H_ */
