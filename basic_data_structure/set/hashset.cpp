#include <map>
using namespace std;

template<typename K, typename V>
class MyHashSet {
public:
        MyHashSet() {

        }
        ~MyHashSet(){

        }

        bool Remove(K k) {
            if (Contains(k))
                return false;
            _container.erase(k);
        }

        bool Contains(K k){
            return _container.has(k);
        }

        bool Add(K k, V v) {
            if (Contains(k))
                return false;
            _container.insert(std::make_pair(k,v));
        }

        auto&& Get(K k) {
            return _container.find(k);
        }
private:
    unordered_map<K, V> _container;
};