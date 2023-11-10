#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int target = 0 - nums[i];
            auto twoSumRes = twoSum(nums, i+1, target);
            for(const auto res: twoSumRes) {
                ret.push_back({nums[i], res[0], res[1]});
            }
            int currentVal = nums[i];
            while (i < nums.size()-1 && nums[i] == nums[i+1])
                i++;
        }

        return ret;
    }
private:
    vector<vector<int>> twoSum(vector<int>& nums, int leftIdx, int targetValue) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int left = leftIdx, right = nums.size()-1;
        while(left < right) {
            int leftVal = nums[left];
            int rightVal = nums[right];
            int sum = leftVal + rightVal;
            if (sum < targetValue) {
                left++;
                // skip repeat nums;
                while(left < right && nums[left] == leftVal)
                    left++;
            } else if (sum > targetValue) {
                right--;
                while(left < right && nums[right] == rightVal)
                    right--;
            } else {
                ret.push_back({leftVal, rightVal});
                while(left < right && nums[right] == rightVal)
                    right--;
                while(left < right && nums[left] == leftVal)
                    left++;
            }

        }
        return ret;
    }
};