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

class StockSpanner2 {
public:
    StockSpanner2() {

    }
    
    int next(int price) {
        // need to calcute the day of today
        int count = 1;
        while(!_stk.empty() && _stk.top().first < price) {
            count += _stk.top().second;
            _stk.pop();
        }
        _stk.push({price, count});

        return count;
    }
private:
    // 记录两个，一个是 天数的index，一个是price用于在stack里去做比较。
    // {price, count};
    stack<std::pair<int, int>> _stk;
};