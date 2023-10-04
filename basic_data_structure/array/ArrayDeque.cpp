#include <vector>

using namespace std;
const int kDefaultSize = 10;
// 1. 考虑异常情况
// 2. 统一考虑size
// 3. 考虑扩容及缩容
// 4. 记住 [fist, last)
// 5. 两种情况
// first --- last
// --last -- first--
template<typename T>
class ArrayDeque {
public:
    ArrayDeque(int cap) {
        _container.resize(cap);
    }
    ArrayDeque() {
        _container.resize(kDefaultSize);
    }

    void PushBack(T t) {
        // 扩容
        if (_size == _container.size()) {
            resize(_size*2);
        }

        _container[_last] = t;
        _last++;
        if (_last == _container.size()) {
            _last = 0;
        }

        _size++;
    }

    void PopBack() {
        if (_size == 0) {
            return;
        }

        if (_size == _container.size()/4) {
            resize(_container.size()/2);
        }

        if (_last == 0) {
            _last = _container.size() - 1;
        } else {
            _last--;
        }
        // delete element here;

        _size--;
    }

    void PushFront(T t) {
        if (_size == _container.size())
            return;
        
        // _first 指向的是元素不是空位置，所以要先操指针再来操作赋值
        if (_first == 0) {
            _first = _container.size() - 1;
        } else {
            _first --;
        }
        _container[_first] = t;

        _size++;
    }

    void PopFront() {
        if (_size == 0)
            return;

        if (_size == _container.size()/4) {
            resize(_container.size()/2);
        }

        // delete element here;

        if (_first == _container.size() - 1) {
            _first = 0;
        } else {
            _first++;
        }

        _size--;
    }

    T GetFirst() {
        if (_size == 0)
            throw std::exception{"empty"};
        return _container[_first];
    }

    T GetLast() {
        if (_size == 0)
            throw std::exception{"empty"};
        
        // first... last...
        // last... first...
        if (_last == 0)
            return _container.back();
        
        // last 指向最后一个元素的下一个位置
        return _container[_last - 1];
    }

private:
    void resize(int newCap) {
        vector<T> newConainer(newCap, 0);
        for (int i = 0; i < _size; i++) {
            newConainer[i] = _container[(_first+i) % _contaier.size()];
        }
        _container.swap(newContainer);
        _first = 0;
        _last = _container.size();
    }

    vecotr<T> _container;
    // [0, 0) 区间为左闭右开 均为0表示开始的时候没有值 
    int _first = 0;
    int _last = 0;
    int _size = 0;
};