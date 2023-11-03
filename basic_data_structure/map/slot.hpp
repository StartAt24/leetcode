#include <list>
#include <algorithm>

template<typename Key, typename Value>
class Slot{
public:
    Slot() = default;

    void Set(std::pair<Key, Value> c) {
        if(!Contains(k)) {
            _container.push_back(c);
            _size++;
        } else {
            auto found =  std::find(_container.begin(), _container.end(), [](auto content) {
                return content.first == k;
            });
            found->second = c.second;
        }
        return;
    }

    Value Get(Key k) {
        if (!Contains(k)) {
            throw std::exception("key not exisit");
        }

        auto found =  std::find(_container.begin(), _container.end(), [](auto content) {
            return content.first == k;
        });
        return found->second;
    }

    void Delete(Key k) {
        if (!Contains(k)) {
            throw std::exception("key not exisit");
        }

        auto found =  std::find(_container.begin(), _container.end(), [](auto content) {
            return content.first == k;
        });
        _container.erase(found);
        _size--;
    }

    bool Contains(Key k) {
        auto found =  std::find(_container.begin(), _container.end(), [](auto content) {
            return content.first == k;
        });
        return found != _container.end();
    }

private:
    std::list<std::pair<Key, Value>> _container;
    int _size = 0;
};