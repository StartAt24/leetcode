#include <vector>
#include <list>
#include <map>
// 1. most frequently used data should be put at first position
// 2. if the storage reach maximum, delete the least frequently used data
// 3. if there are multiple data have the same status of frequency, delte the olderest one.
using namespace std;
class LFUCache {
using iter = list<pair<int, int>>::iterator;
public:
    // initialize the capacity
    LFUCache(int capacity): _cap(capacity) {
    }
    
    // get an element by key, return -1 if not exisit;
    int get(int key) {

        return -1;
    }
    
    void put(int key, int value) {
        //1. if exisit, change the cooresponding value and increase the number of frequency.
        //2. if not exisit
        //2.1 not exceed maxiumn, add it and initialize capability
        //2.2 exceed maxium, remove the least frequence one, and add it.
        //if there are multiple frequent elements, delete the older one.
    }

private:
    list<pair<int, int>> _list;
    map<int, iter> _map;
    int _cap;
};