#include <stack>
#include <vector>

// 2, 1, 2, 4, 3
// stack
// 3,
// pop 3
// push 4
// 4
// push 2
// 4, 2
// push 1
// 4, 2, 1
// pop 1
// push 2
// 4, 2, 2  <-- the stack's final data

// if we use queue?
// 2, 1, 2, 4, 3
// queue
// push 3,
// 3
// pop 3
// push 4
// 4
// push 2
// 4, 2
// push 1
// 4, 2, 1
// push 2
// 这里就需要从 4开始遍历了。 之前是从1开始遍历, 并且我需要把这个元素pop出 queue才能拿到下一个
// 然后再将这些元素 放回 queue中。这里增加了复杂性

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();

    vector<int> res;
    stack<int> sortedStk;

    for (int i = n-1; i >=0 ; i--) {
        // 从后向前入栈，其实就是从前向后处理。
        // 并且只保留大于当前元素的元素。
        // 栈的作用就是先进去的后处理。并且从前向后处理会把所有等于当前元素的也全部去掉。
        // 这样留下来的始终是index比较小的元素
        while(!sortedStk.empty() && sortedStk.top() <= nums[i]) {
            sortedStk.pop();
        }

        res.push_back(sortedStk.empty()? -1 : sortedStk.top());
        sortedStk.push(nums[i]);
    }
#if 0 
    for (int i = 0; i < nums.size(); i++) {
        while (!sortedStk.empty() && sortedStk.top() >= nums[i]) {
            sortedStk.pop();
        }
        res.push_back(sortedStk.empty()? -1 : sortedStk.top());
        sortedStk.push(nums[i]);

    }
#endif

    return res;
}