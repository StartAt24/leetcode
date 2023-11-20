#include <map>
#include <vector>
using namespace std;

// array hash map对key有 O(1)时间内,等概率的随机访问能力
template<typename K, typename V>
class ArrayHashMap{
    using iter = vector<pair<K, V>>::iterator;
public:
    iter Get(K k) {
        return _map[k];
    }

    void Set(K k, V v) {
        auto it = _container.find(k);
        if (it != _map.end()) {
            it->second.second = v;
        } else {
            auto p = std::make_pair(k,v);
            _container.push_back(p);
            _map[k] =std::prev(_container.end())
        }
    }

    void delete(K k) {
        auto it = _map[k];
        _container.erase(it);
        _map.erase(it);
    }


private:
    vector<pair<K,V>> _container;
    unordered_map<K, vector<pair<K,V>>::iterator> _map;
};