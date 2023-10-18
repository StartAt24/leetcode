#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> res(n, -1);
        // double the size of vector to solve the loop issue.
        // here we use % to simulate it. 
        for(int i = n*2-1; i >=0; i--) {
            while(!stk.empty() && stk.top() <= nums[i%n]) {
                stk.pop();
            }

            res[i%n] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i%n]);
        }

        return res;
    }
};