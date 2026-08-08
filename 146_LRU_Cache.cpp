#include<unordered_map>
#include<list>

using namespace std;

class LRUCache {
private:
    int capacity;

    // key -> {value, iterator to the key in list}
    unordered_map<int, pair<int, list<int>::iterator>> cache;

    // Most recently used at front
    // Least recently used at back
    list<int> lru;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        // Move key to front because it is recently used
        lru.erase(cache[key].second);
        lru.push_front(key);
        cache[key].second = lru.begin();

        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Remove old position
            lru.erase(cache[key].second);

            // Update value
            cache[key].first = value;
        }
        else {
            // If cache is full, remove least recently used
            if (cache.size() == capacity) {
                int lruKey = lru.back();

                lru.pop_back();
                cache.erase(lruKey);
            }
        }

        // Add key to front
        lru.push_front(key);
        cache[key].second = lru.begin();
        cache[key].first = value;
    }
};