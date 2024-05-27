#include <vector>
using std::vector;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // _dp represent the length of subsequence when at index i;
        // 所有的dp最小应该就是1，因为以自己为起点，最少也是1
        _dp.resize(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    _dp[i] = max(_dp[i], _dp[j] + 1);
            }
        }

        // auto maxVal = std::max_element(_dp.begin(), _dp.end());
        // return *maxVal;
        int res = 0;
        for ( int i = 0; i < nums.size(); i++) {
            res = max(res, _dp[i]);
        }
        return res;
    }
private:
    vector<int> _dp;
};