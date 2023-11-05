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
        size_t idx = 
    }

    void Remove(Key k) {

    }

    void Add(key k) {
        
    }

private:
    size_t hash(Key k) {

    }

    void resize(int newCap) {

    }

private:
    vector<Slot<typename Key, typename Value>> _container;
    int _cap{0};
};