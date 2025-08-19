
#include <iostream>
#include <vector>
#include <map>

template <typename K, typename V>
class MapADT {
private:
    std::map<K, V> data;

public:
    bool empty() {
    	return data.empty();
    }

    void insert(const K& key, const V& value) {
        data[key] = value;
    }

    void erase(const K& key) {
        data.erase(key);
    }

    std::map<K, V>& getMap() {
        return data;
    }

    typename std::map<K, V>::iterator begin() {
    	return data.begin();
    }

    typename std::map<K, V>::iterator end() {
    	return data.end();
    }

    typename std::map<K, V>::iterator firstEntry() {
        return data.empty() ? data.end() : data.begin();
    }

    typename std::map<K, V>::iterator lastEntry() {
        return data.empty() ? data.end() : --data.end();
    }

    typename std::map<K, V>::iterator ceilingEntry(const K& key) {
        auto it = data.lower_bound(key);
        return it;
    }

    typename std::map<K, V>::iterator floorEntry(const K& key) {
        auto it = data.upper_bound(key);
        if (it == data.begin()) return data.end();
        return --it;
    }

    typename std::map<K, V>::iterator lowerEntry(const K& key) {
        auto it = data.lower_bound(key);
        return (it == data.begin() || data.empty()) ? data.end() : --it;
    }

    typename std::map<K, V>::iterator higherEntry(const K& key) {
        auto it = data.upper_bound(key);
        return it;
    }

    typename std::map<K, V>::iterator BinarySearch(std::map<K, V>& L, const K& key, typename std::map<K, V>::iterator low, typename std::map<K, V>::iterator high) {

      	if ( low->first > high->first ) {  // Base case: Key not found
            return L.end();
        }

        auto mid = std::next(low, std::distance(low, high) / 2); // Calculate mid iterator
    	std::cout << " [" << low->first << "," << mid->first << "," << high->first << "] ";
        if (key == mid->first) {
            return mid;
        } else if (key < mid->first) {
            return BinarySearch(L, key, low, std::prev(mid));
        } else {
            return BinarySearch(L, key, std::next(mid), high);
        }
    }

    void display() {
    	std::cout << "{ ";
        for (const auto& entry : data) {  // Fixed structured binding issue
            std::cout << "(" << entry.first << "," << entry.second << ") ";
        }
        std::cout << " }" << std::endl;
    }
};

int main() {
    MapADT<int, std::string> map;

    map.insert(9, "F");
    map.insert(17, "I");
    map.insert(4, "B");
    map.insert(25, "L");
    map.insert(22, "K");
    map.insert(8, "E");
    map.insert(2, "A");
    map.insert(37, "P");
    map.insert(14, "H");
    map.insert(7, "D");
    map.insert(28, "N");
    map.insert(12, "G");
    map.insert(27, "M");
    map.insert(5, "C");
    map.insert(33, "O");
    map.insert(19, "J");

    std::cout << "Map contents: ";
    map.display();

    auto it = map.firstEntry();
    if (it != map.lastEntry()) std::cout << "First Entry: (" << it->first << "," << it->second << ")" << std::endl;

    it = map.lastEntry();
    if (!map.empty())		   std::cout << "Last Entry:  (" << it->first << "," << it->second << ")" << std::endl;

    it = map.ceilingEntry(15);
    if (it != map.lastEntry()) std::cout << "Ceiling Entry (>=15): (" << it->first << "," << it->second << ")" << std::endl;

    it = map.floorEntry(15);
    if (it != map.lastEntry()) std::cout << "Floor Entry (<=15): (" << it->first << "," << it->second << ")" << std::endl;

    it = map.lowerEntry(22);
    if (it != map.lastEntry()) std::cout << "Lower Entry (<22): (" << it->first << "," << it->second << ")" << std::endl;

    it = map.higherEntry(22);
    if (it != map.lastEntry()) std::cout << "Higher Entry (>22): (" << it->first << "," << it->second << ")" << std::endl;

    // Performing Binary Search on key 27
    std::cout << " The result of BinarySearch(&map, 27, 1, 39) : ";
    std::map<int, std::string>::iterator it2 = map.BinarySearch(map.getMap(), 22, map.firstEntry(), map.lastEntry());

    if (it2 != map.end()) { // Ensure key exists
         std::cout << std::endl << "Key(" << it2->first << ") is found." << std::endl;
    } else {
    	std::cout << std::endl << "Key(22) is found." << std::endl;
    }

    return EXIT_SUCCESS;
}


