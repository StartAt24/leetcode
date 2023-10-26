#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ret(n, 0);
        stack<int> stk;

        for(int i = n-1; i>=0; i--) {
            while(!stk.empty() && stk.top() > prices[i])
            {
                stk.pop();
            }
            ret[i] = stk.empty()? prices[i] : prices[i] - stk.top();
            stk.push(prices[i]);
        }

        return ret;
    }
};