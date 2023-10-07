#include <stack>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(auto c: s) {
            if(c == ')') {
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                    stk.push(c);
            }
            else {
                stk.push(c);
            }
        }
        return stk.size();
    }
};