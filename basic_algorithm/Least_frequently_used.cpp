#include <vector>
#include <list>
#include <map>
// 1. most frequently used data should be put at first position
// 2. if the storage reach maximum, delete the least frequently used data
// 3. if there are multiple data have the same status of frequency, delte the olderest one.
using namespace std;
class LinkedHashSet;
class LFUCache {
using iter = list<pair<int, int>>::iterator;
public:
    // initialize the capacity
    LFUCache(int capacity): _cap(capacity) {
    }
    
    // get an element by key, return -1 if not exisit;
    int get(int key) {
        if (!_keyToVal.contains(key))
            return -1;
        
        increaseFreq(key);
        return _keyToVal(key);
    }
    
    void put(int key, int value) {
        //1. if exisit, change the cooresponding value and increase the number of frequency.
        //2. if not exisit
        //2.1 not exceed maxiumn, add it and initialize capability
        //2.2 exceed maxium, remove the least frequence one, and add it.
        //if there are multiple frequent elements, delete the older one.
        if (_cap <= 0)
            return;
        if (_keyToVal.contains(key)) {
            _keyToVal[key] = value;
            increaseFreq(key);
            return;
        }

        if (_keyToVal.size() == _cap) {
            removeMinFreqKey();
        }

        _keyToVal[key] = value;
        _keyToFreq[key] = 1;

        _freqToKeys.at(1).push_back(key);
        _minFreq = 1;
    }
private:
    void removeMinFreqKey() {
        auto keyList = _freqToKeys.get(_minFreq);
        auto deletedkey = keyList.front();
        keyList.pop_front();
        if (keyList.empty()) {
            _freqToKeys.erase(_minFreq);
            // Q: need to update minFreq?
            // A: no need to update, since this function always called before add new element,
            // minFreq will be update to 1 anyway.
        }
        _keyToVal.erase(deletedkey);
        _keyToFreq.erase(deletedKey);
    }

    void increaseFreq(int key) {
        int freq = _keyToFreq(key);
        _keyToFreq[key]++;

        _freqToKeys[freq].erase[key];

        _freqToKeys[freq+1].push_back(key);

        if(_freqToKeys[freq].empty()){
            _freqToKeys.erase(freq);
            if (freq == _minFreq)
                _minFreq++;
        }
    }

private:
    int _cap;

    // mapping of key to val, KV table;
    unordered_map<int, int> _keyToVal;
    // mapping of key to freq, KF table;
    unordered_map<int, int> _keyToFreq;
    // frequency 1 to N keys. Need to have a data structure to store key, and keep key has sequence.
    // mapping of freq to key, FK table;
    unordered_map<int, LinkedHashSet> _freqToKeys;
    int _minFreq = 0;
};