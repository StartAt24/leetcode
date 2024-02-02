#include <vector>
#include <stack>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // min stack and max stack?
        // 7, 1, 5, 3, 6, 4

        // 4
        // 6, 4
        // 
        vector<int> sortedPrices;
        for (int i = prices.size()-1; i >= 0; i--) {
            while(!_minStack.empty() && prices[i] <= _minStack.top()) {
                _minStack.pop();
            }
            if (!_minStack.empty())
                sortedPrices.push_back(_minStack.top());

            _minStack.push(prices[i]);
        }
        return sortedPrices.back()- sortedPrices.front();
    }
private:
    std::stack<int> _minStack;
    std::stack<int> _maxStack;
};