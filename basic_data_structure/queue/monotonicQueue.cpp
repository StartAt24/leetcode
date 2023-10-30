#include <queue>

using namespace std;

class MonotonicQueue{

    void pushBack(int val){
        _container.push_back(val);

        // 当前值比队列列的尾巴值大
        while(!_maxQue.empty() && val > _maxQue.back()) {
            _maxQue.pop_back();
        }
        _maxQue.push_back(val);

        while(!_minQue.empty() && val < _minQue.back()) {
            _minQue.pop_back();
        }
        _minQue.push_back(val);
    }

    void popFront() {
        int frontVal = _container.front();
        _container.pop_front();

        if(frontVal == _minQue.front()) {
            _minQue.pop_front();
        }

        if(frontVal == _maxQue.front()) {
            _maxQue.pop_front();
        }
    }

    int size() {
        return _container.size();
    }

    int max() {
        return _maxQue.front();
    }

    int min() {
        return _minQue.front();
    }

private:
    deque<int> _container;
    deque<int> _maxQue;
    deque<int> _minQue;
};