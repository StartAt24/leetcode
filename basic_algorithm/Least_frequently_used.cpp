#include <vector>
#include <list>
#include <map>

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