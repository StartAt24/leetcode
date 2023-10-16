#include <stack>
#include <vector>

// 2, 1, 2, 4, 3
// 3
// 4
// 4, 2,
// 4, 2, 1,
// 4, 2, 2

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();

    vector<int> res;
    stack<int> sortedStk;

    for (int i = n-1; i >=0 ; i--) {
        while(!sortedStk.empty() && sortedStk.top() <= nums[i]) {
            sortedStk.pop();
        }

        res.push_back(sortedStk.empty()? -1 : sortedStk.top());
        sortedStk.push(nums[i]);
    }

    return res;
}