#include <vector>
using namespace std;

template<typename K, typename V>
class Map{
public:
    Map(int cap): _cap(cap){
        _container.resize(cap);
    }

    void Insert(pair<K, V> elem) {

    }

    void Delete(K k) {
        // find the target element.
        // remove this element.
        // move the rest element that shares the same hash number.
        //NB! 具体的move方法是，先Delete 再 Insert。 这样后续的元素会自动往前挪动。
        _size--;
    }

    bool Contains(K k) {
        auto i = Hash(k);


    }

private:
    void Resize() {

    }
    size_t Hash(K k) {
        return std::hash(k) % _cap;
    }

    int GetIndex(K k) {
        auto idx = Hash(k);

        // how to determine if it meet an empty slot?
        while(_container[idx] != nullptr) {
            if (_container[idx].first == k)
                return idx;
            idx = (idx+1)%_cap;
        }

        return -1;
    }

private:
    vector<pair<typename K, typename V>> _container;
    int _cap{0};
    int _size{0};
};