class LFUCache {

    // value, freq, and iterator pointing to its position in freqList[freq]
    struct NodeInfo {
        int value;
        int freq;
        list<int>::iterator it;  // points to key inside freq list
    };

    int cap;                 // capacity
    int minFreq;             // minimum frequency currently present
    unordered_map<int, NodeInfo> mp;       // key -> info
    unordered_map<int, list<int>> freqList; // freq -> keys (front = most recent)

    // Helper: increase frequency of a key (used in get and put existing)
    void touch(int key) {
        int f = mp[key].freq;

        // Remove key from its current frequency list
        freqList[f].erase(mp[key].it);

        // If this frequency list became empty
        // and it was the min frequency, increase minFreq
        if (freqList[f].empty()) {
            freqList.erase(f);
            if (minFreq == f) minFreq++;
        }

        // Move key to next frequency list (f+1) at the front (most recent)
        int newF = f + 1;
        freqList[newF].push_front(key);

        // Update key info
        mp[key].freq = newF;
        mp[key].it = freqList[newF].begin();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        // If key not found
        if (mp.find(key) == mp.end()) return -1;

        // Use it => frequency increases
        touch(key);

        return mp[key].value;
    }

    void put(int key, int value) {
        // If capacity is 0, we cannot store anything
        if (cap == 0) return;

        // If key already exists: update value and increase freq
        if (mp.find(key) != mp.end()) {
            mp[key].value = value;
            touch(key);
            return;
        }

        // If cache is full, evict LFU key (and LRU among them)
        if ((int)mp.size() == cap) {
            // The least frequently used keys are in freqList[minFreq]
            // Evict the least recently used among them => back of the list
            int evictKey = freqList[minFreq].back();
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty()) {
                freqList.erase(minFreq);
            }

            mp.erase(evictKey);
        }

        // Insert new key with freq = 1
        minFreq = 1;
        freqList[1].push_front(key);

        mp[key] = {value, 1, freqList[1].begin()};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */