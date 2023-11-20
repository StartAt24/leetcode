#include <map>
#include <vector>
using namespace std;

// array hash map对key有 O(1)时间内,等概率的随机访问能力
template<typename K, typename V>
class ArrayHashMap{
public:


private:
    vector<pair<K,V>> _container;
    unordered_map<K, vector<pair<K,V>>::iterator> _map;
};