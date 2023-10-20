#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    // 每次滑动之后应该想办法不全部比较一遍, 借助上次比较的结果
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // [1, 3, -1, -3, 5, 3, 6, 7]

        // push back 1
        // [1]
        // pop front 1
        // push back 3
        // [3]
        // push -1
        // [3, -1]
        // push -3
        // [3, -1, -3]


        // 单调队列。
        MonotonicQueue window;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (i < k -1) {
                // 先将窗口 前k-1个元素 放进去
                window.push(nums[i]);
            } else {
                // 窗口开始向前滑动
                // 加入新的元素
                window.push(nums[i]);

                // 此时此刻 queue中刚好有 k个元素.
                res.push_back(window.max());
                // 移除最先进入队列的元素
                // 因为 i 是队列里的 第 k个元素 即 i - idx + 1 = k
                // idx = i - k + 1;
                window.pop(nums[i - k + 1]);
            }
        }

        return res;
    }
private:
    class MonotonicQueue{
    public:
        // enqueue 操作，在队列尾加入n
        void push(int n){
            // 将小于 n的元素全部删除
            while (!_container.empty() && _container.back() < n) {
                _container.pop_back();
            }
            // 将 n加入尾巴
            _container.push_back(n);
            // 所以 队列里从头到尾 是不连续的 从大到小排列的
        }
        // 返回当前队列中的最大值
        int max() {
            return _container.front();
        }

        // 如果队列头元素是n, 则删除它
        void pop(int n) {
            if(_container.front() == n) {
                _container.pop_front();
            }
        }
    private:
        deque<int> _container;
    };
};
