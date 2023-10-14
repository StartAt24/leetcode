#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    // 每次滑动之后应该想办法不全部比较一遍, 借助上次比较的结果
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxVec;
        queue<int> maxStk;

        for (int i = 0; i <k-1; i++) {
            if (maxStk.empty() || maxStk.back() <= nums[i]) {
                maxStk.push(nums[i]);
            } else {
                maxStk.push(maxStk.back());
            }
        }

        // 7,2,4
        // k = 2;
        // 7,7


        int left = 0, right = k-1;
        while (right < nums.size()) {
            if (right - left == k) {
                // need to pop left;
                // and left is the biggest value;
                while (!maxStk.empty() && maxStk.front() == nums[left])
                    maxStk.pop();
                left++;
            }

            if (maxStk.empty() || maxStk.back() < nums[right]) {
                maxStk.push(nums[right]);
            } else {
                maxStk.push(maxStk.back());
            }

            right++;
            maxVec.push_back(maxStk.back());
        }
        return maxVec;
    }
};