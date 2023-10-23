#include <vector>

using namespace std;
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        _container.resize(k);
        _cap = k;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;

        _container[_last] = value;
        _last++;
        _last = _last % _cap;
        _size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;

        _first++;
        _first = _first % _cap;
        _size--;
        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        return _container[_first];
    }
    
    int Rear() {
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
        return _size == _container.size();
    }
private:
    // _first point to the first place that can be remove.
    int _first = 0;
    // _last point to the first place that can be insert.
    int _last = 0;
    int _size = 0;
    int _cap = 0;
    std::vector<int> _container;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */