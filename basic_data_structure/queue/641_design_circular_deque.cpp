#include <vector>
using namespace std;

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        _container.resize(k);
        _cap = k;
    }
    
    bool insertFront(int value) {
        if (isFull())
            return false;
        
        _first--;
        if (_first == -1)
            _first = _cap - 1;

        _container[_first] = value;
        _size++;
        return true;     
    }
    
    bool insertLast(int value) {
        if (isFull())
            return false;
        
        _container[_last] = value;
        _last++;
        if (_last == _cap)
            _last = 0;

        _size++;
        return true;     
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;
        
        _first++;
        if (_first == _cap)
            _first = 0;

        _size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;
        _last--;
        if (_last == -1)
            _last = _cap - 1;

        _size--;
        return true;     
    }
    
    int getFront() {
        if (isEmpty())
            return -1;
        return _container[_first];
    }
    
    int getRear() {
        if (isEmpty())
            return -1;

        int lastIndex = _last - 1;
        if (lastIndex == -1)
            lastIndex = _cap - 1;
        return _container[lastIndex];
    }
    
    bool isEmpty() {
        return _size == 0;
    }
    
    bool isFull() {
        return _size == _cap;
    }
private:
    vector<int> _container;
    int _first = 0;
    int _last = 0;
    int _size = 0;
    int _cap = 0;
};