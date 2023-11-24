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
    LFUCache(int capacity): _cap(capacity) {
    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {

    }
private:
    list<pair<int, int>> _list;
    map<int, iter> _map;
    int _cap;
};