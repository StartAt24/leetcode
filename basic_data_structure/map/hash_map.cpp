#include "slot.hpp"
#include <vector>

using namespace std;

template<typename Key, typename Value>
class MyHashMap{
public:

private:
    vector<Slot<typename Key, typename Value>> _container;

};