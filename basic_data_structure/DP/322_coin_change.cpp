#include "vector"
using std::vector;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        _cache.resize(amount+1, -1);
        return dp(coins, amount);
    }
private:
    int dp(vector<int>& coins, int n) {
        // base case;

        if (n == 0)
            return 0;
        if (n < 0)
            return -1;
        // 直接获取最优解
        if (_cache[n] != -1) return _cache[n];

        int res = INT_MAX;
        for (auto coin : coins) {
            int subProblem = dp(coins, n - coin);
            if (subProblem == -1)
                continue;
            res = min(res, subProblem + 1);
        }

        int retVal = res == INT_MAX ? -1 : res;
        _cache[n] = retVal;
        return retVal;
    }

    int dp(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        for (int i = 0; i < amount; i++) {
            for (int coin : coins) {
                if (i - coin < 0)
                    continue;
                dp[i] = min(dp[i], i + dp[i-coin]);
            }
        }
        return (dp[amount] == amount+1) ? -1 : dp[amount];
    }

    vector<int> _cache;
};