#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ret(n);
    for(int i = n-1; i >=0 ; i--) {
        while(!stk.empty() && stk.top() <= nums[i]) {
            stk.pop();
        }
        // 现在栈顶就是 nums[i]身后更大的元素。
        ret[i] = stk.empty()? -1 : stk.top();
        stk.push(nums[i]);
    }
    return ret;
}

vector<int> nextGreaterOrEqualElement(vector<int> nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ret(n);
    for(int i = n-1; i >=0 ; i--) {
        // 如果要保留等于的元素，应该只把小余他的去掉
        while(!stk.empty() && stk.top() < nums[i]) {
            stk.pop();
        }
        // 现在栈顶就是 nums[i]身后更大的元素。
        ret[i] = stk.empty()? -1 : stk.top();
        stk.push(nums[i]);
    }
    return ret;
}

vector<int> nextLessElement(vector<int> nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ret(n);
    for(int i = n-1; i >=0 ; i--) {
        // 如果是找下一个更小的元素，应该把大于当前元素的全部去掉
        while(!stk.empty() && stk.top() >= nums[i]) {
            stk.pop();
        }
        // 现在栈顶就是 nums[i]身后更大的元素。
        ret[i] = stk.empty()? -1 : stk.top();
        stk.push(nums[i]);
    }
    return ret;
}

vector<int> nextLessOrEqualElement(vector<int> nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ret(n);
    for(int i = n-1; i >=0 ; i--) {
        // 去掉等于号
        while(!stk.empty() && stk.top() > nums[i]) {
            stk.pop();
        }
        // 现在栈顶就是 nums[i]身后更大的元素。
        ret[i] = stk.empty()? -1 : stk.top();
        stk.push(nums[i]);
    }
    return ret;
}

vector<int> prevGreaterElement(vector<int> nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ret(n);
    for(int i = 0; i < n; i++) {
        // 删除掉当前元素前面比他小的元素
        while(!stk.empty() && stk.top() <= nums[i]) {
            stk.pop();
        }
        // 现在栈顶就是 nums[i]身后更大的元素。
        ret[i] = stk.empty()? -1 : stk.top();
        stk.push(nums[i]);
    }
    return ret;
}

vector<int> prevGreaterOrEqualElement(vector<int> nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ret(n);
    for(int i = 0; i < n; i++) {
        // 删除掉当前元素前面比他小的元素
        while(!stk.empty() && stk.top() < nums[i]) {
            stk.pop();
        }
        // 现在栈顶就是 nums[i]身后更大的元素。
        ret[i] = stk.empty()? -1 : stk.top();
        stk.push(nums[i]);
    }
    return ret;
}

vector<int> prevLessElement(vector<int> nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ret(n);
    for(int i = 0; i < n; i++) {
        // 删除掉当前元素前面比他大的元素
        while(!stk.empty() && stk.top() >= nums[i]) {
            stk.pop();
        }
        // 现在栈顶就是 nums[i]身后更大的元素。
        ret[i] = stk.empty()? -1 : stk.top();
        stk.push(nums[i]);
    }
    return ret;
}

vector<int> prevLessOrEqualElement(vector<int> nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ret(n);
    for(int i = 0; i < n; i++) {
        // 删除掉当前元素前面比他大的元素
        while(!stk.empty() && stk.top() > nums[i]) {
            stk.pop();
        }
        // 现在栈顶就是 nums[i]身后更大的元素。
        ret[i] = stk.empty()? -1 : stk.top();
        stk.push(nums[i]);
    }
    return ret;
}
