#include <vector>
#include <stack>
#include <queue>

using std::vector;
using namespace std;
class MonotonicQueue{
public:
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
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // we need to have a 
        int n = nums.size();
        // preSum 和 array是错开一位的
        vector<int> preSum(2*n+1, 0);
        for (int i = 1; i < preSum.size(); i++) {
            preSum[i] = preSum[i-1] + nums[(i-1)%n];
        }

        MonotonicQueue window;
        // loop presum array
        int maxVal = std::numeric_limits<int>::min();
        // push 进一个0为了方便后续的迭代？
        window.pushBack(0);

        for (int i = 1; i < preSum.size(); i++) {
            // 先判断
            maxVal = max(maxVal, preSum[i] - window.min());
            if (window.size() == n)
                window.popFront();
            
            window.pushBack(preSum[i]);
        }

        return maxVal;
    }
};