#include <list>
#include <map>
using namespace std;
// least recently used.
// the one that just used should at the top of the data structure.
class LRUCache {
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        auto found = _map.find(key);
        if (found != _map.end()) {
            // 每次 get理论上应该要 update container，确保刚用过的在前面， 
            // 我们就放在list的前面吧。
            // 将 found放在链表的最前面
            auto backUp = std::make_pair(found->first, found->second);
            removeElement(found);
            addFront(backUp.first, backUp.second);
            return backUp.second;
        }
        return -1;
    }
    
    // 往末尾放
    void put(int key, int value) {
        if (_container.size() == _cap)
            removeLRU();

        _container.push_back(std::make_pair(key, value));
    }

private:
    void removeElement(list<pair<int, int>>::iterator iter) {
        _container.erase(iter);
        _map.erase(iter->first);
    }

    void addFront(int k, int v) {
        _container.push_front(std::make_pair(k,v));
        _map[k] = _container.begin();
    }

    void removeLRU() {
        auto lastElement = _container.back();
        int k = lastElement.first;
        _map.erase(k);
        _container.pop_back();
    }

    unordered_map<int, list<pair<int, int>>::iterator> _map;
    list<pair<int, int>> _container;
    int _cap{0};
};