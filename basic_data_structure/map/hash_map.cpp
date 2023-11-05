#include "slot.hpp"
#include <vector>

using namespace std;

template<typename Key, typename Value>
class MyHashMap{
public:
    MyHashMap(int cap): _cap(cap) {
        _container.reserve(cap);
    }

    ~MyHashMap() {

    }

    bool Contains(Key k) {
        auto& slot = _container[hash(k)];
        return slot.Contains(k);
    }

    void Remove(Key k) {
        auto& slot = _container[hash(k)];
        slot.Delete(k);
        _size--;
    }

    void Insert(std::pair<Key,Valu> v) {
        if (_size >= _cap*0.75) {
            resize(2*_cap);
        }
        auto idx = hash(k);
        auto& list = _container[idx];
        if (list.Contains(v.first)) 
            _size++;

        list.Set(v);
    }

private:
    // get the slot idx;
    size_t hash(Key k) {
        return std::hash(k) % _cap;
    }

    void resize(int newCap) {
        _cap = newCap;
        auto newMap =  MyHashMap(newCap);

        // rehash
        // 1. loop all slot
        for (auto& slot : _container) {
            for (auto &kv : slot.Entry()) {
                newMap.Insert(kv);
            }
        }
        // swap
        std::swap(this, newMap);
    }

private:
    vector<Slot<typename Key, typename Value>> _container;
    int _cap{0};
    int _size{0};
};