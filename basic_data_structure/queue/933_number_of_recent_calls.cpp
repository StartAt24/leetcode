#include <queue>

class RecentCounter {
public:
    RecentCounter() {

    }
    
    // get request happened in 3000 millisends
    // including the new request.
    int ping(int t) {
        _timeQue.push(t);
        
        while(!_timeQue.empty() && t - _timeQue.front() > _expireTime) {
            _timeQue.pop();
        }
        return _timeQue.size();
    }
private:
    std::queue<int> _timeQue;
    int _expireTime = 3000;
};