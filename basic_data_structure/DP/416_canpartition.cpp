#include <vector>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        // can't be divided into two equal parts.
        if (sum % 2 != 0)
            return false;
        
        int target = sum / 2;
        // dp数组的定义，_dp[i][j] = x
        // 第i个物品，背包容量为j 时，若x为true,则说明可以恰好将背包装满
        // 例如 _dp[4][9] = true, 含义为，容量为9的背包，若只在前4个物品中进行选择，
        // 可以有一种办法将背包填满
        vector<vector<int>> _dp(nums.size()+1, vector<bool>(target+1));

        // base case:
        for (int i = 0; i < _dp.size(); i++) {
            // 当前重量为0的时候 说明刚好装满
            _dp[i][0] = true;
        }

        for ( int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                int currentVal = nums[i - 1];
                // j表示当前剩余的重量
                // 那么只能不放了
                if (j - currentVal < 0 ) {
                    _dp[i][j] = _dp[i-1][j];
                } else {
                    // 两种情况，
                    // 1. 将 valIdx 放进背包
                    bool put = _dp[i-1][j-currentVal];
                    // 2. 不将 valIdx 放进背包
                    bool notPut = _dp[i-1][j];

                    _dp[i][j] = put || notPut;
                }
            }
        }

        return _dp[nums.size()][target];
    }
};