#include <vector>
#include <stack>

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

    bool empty(){
        return _container.empty();
    }

private:
    deque<int> _container;
    deque<int> _maxQue;
    deque<int> _minQue;
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // pre sum array
        // 用来快速计算和
        int size = nums.size();
        vector<long> preSum(size + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            preSum[i+1] = preSum[i] + nums[i];
        }
        int left = 0, right = 0;
        int len = INT_MAX;

        while (right < preSum.size()) {
            _window.pushBack(nums[right]);
            right++;

            // 这里right已经+1了
            // 说明得到了符合条件的子数组，缩小窗口，使得子数组长度尽可能小
            while(right < preSum.size() && !_window.empty() && preSum[right] - _window.min() >= k) {
                len = min(len, right - left);
                _window.popFront();
                left++;
            }
        }
        return len == INT_MAX ? -1 : len; 
    }
private:
    MonotonicQueue _window;
};
