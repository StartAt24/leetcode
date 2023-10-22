#include <queue>
class MovingAverage{
public:
    MovingAverage(int size) {
        _cap = size;
    }

    double next(int val) {
        _dataQue.push(val);
        _sum += val;
        if (_dataQue.size() > _cap){
            _sum -= _dataQue.front();
            _dataQue.pop();
        }

        return _sum/_dataQue.size();
    }
private:
    std::queue<int> _dataQue;
    int _cap{0};
    double _sum{0};
};