#include <vector>
using namespace std;

class Solution {
public:
    // 每次滑动之后应该想办法不全部比较一遍, 借助上次比较的结果
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxVec;
        int firstMax = nums[0];
        for(int i = 0; i < k; i++) {
            firstMax = std::max(nums[i], firstMax);
        }

        maxVec.push_back(firstMax);

        int currentIdx = k;
        while (currentIdx < nums.size()) {
            if (nums[currentIdx] > maxVec.back()) {
                maxVec.push_back(nums[currentIdx]);
            } else {
                maxVec.push_back(maxVec.back());
            }
            currentIdx++;
        }
        return maxVec;
    }
};