#include <list>

template<typename Key, typename Value>
class Slot{
public:

private:
    std::list<std::pair<Key, Value>> _container;
};