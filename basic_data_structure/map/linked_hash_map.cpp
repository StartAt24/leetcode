// use a list to store all the key value pair.
// use the actual map to store a mapping between k and pair
// looks like use two data struture at the same time.
#include <map>
#include <list>

template<typename Key, typename Value>
class MyMap{
public:
    void insert(Key k, Value v){
        Node *n = new Node(k, v);
        _container.insert(k, n);
        _keyList.push_back(n);
    }

    void erase(Key k){
        auto node = _container.find(k);
        node->_prev->_next = node->_next;
        node->_next->_prev = node->_prev;
        _container.erase(k);
    }

    void swap(){

    }

    void clear() {

    }

    Value find(Key k) {
        auto found = _container.find(k);
        if(found == _container.end()) {
            throw std::exception("not found");
        } else {
            return found->_v;
        }
    }

    int count() {
        return _keyList.size();
    }
    struct Node{
        Node(Key k, Value v) {
            _k = k;
            _v = v;
        }

        Key _k;
        Value _v;
        Node* _prev;
        Node* _next;
    };

private:
    std::unordered_map<Key, Node*> _container;
    std::list<Node*> _keyList;
};

template<typename K, typename V>
class CLinkedHashMap{
    using iter = std::unordered_map<K, V>::iterator;
public:
    iter Get(K k) {
        return _map[k];
    }

    void Set(K k, V v) {
        auto it = _map.find(k);
        if (it != _map.end()) {
            // modify
            it->second.second = v;
        } else {
            // add new
            auto p = std::make_pair(k, v);
            _list.push_back(p);
            _map[k] = std::prev(_list.end());
        }
    }

    void delete(K k) {
        auto it = _map[k];
        _list.erase(it);
        _map.erase(k);
    }


private:
    std::list<std::pair<K, V>> _list;
    // map里存放的是 K -> Node(K,V) 的mapping.
    std::unordered_map<K, std::list<std::pair<K,V>>::iterator> _map;
};