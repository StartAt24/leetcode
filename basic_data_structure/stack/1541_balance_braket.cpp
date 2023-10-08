#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        stack<char> stk;  
        int cnt = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == ')' && s[i+1] == ')') {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else {
                    stk.push(s[i]);
                }
            } else {
                stk.push(s[i]);
            }
        }

    }
};