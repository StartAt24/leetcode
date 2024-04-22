#include <vector>
#include <stack>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = -1;
        int pre = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] >= pre)
                continue;
            else {
                pre = prices[i];
            }

            for (int j = i; j< prices.size(); j++) {
                int val = prices[j] - prices[i];
                max = std::max(val, max);
            }
        }
        return max;
    }
};