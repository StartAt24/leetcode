#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
public:
    StockSpanner() {

    }
    
    int next(int price) {
        // first need to store price;
        // second need to
        _historyPrice.push_back(price);
        return span();
    }
private:
    int span() {
        int n = _historyPrice.size();
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && _historyPrice[stk.top()] <= _historyPrice[i]) {
                stk.pop();
            }
            if (i == n-1){
                return stk.empty()? i+1 : i - stk.top();
            }
            stk.push(i);
        }
        return 0;
    }

    vector<int> _historyPrice;
};