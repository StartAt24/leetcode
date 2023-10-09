#include <stack> 
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_map<string, int> op {
            {"+", 1},
            {"-", 1},
            {"*", 1},
            {"/", 1}
        };
        for (auto c : tokens) {
            if (op.contains(c)) {
                int r = stk.top();
                stk.pop();
                int l = stk.top();
                stk.pop();

                if (c == "+") {
                    stk.push(l + r);
                }

                if (c == "-") {
                    stk.push(l - r);
                }

                if (c == "*") {
                    stk.push(l * r);
                }

                if (c == "/") {
                    stk.push(l / r);
                }
            }
            else {
                stk.push(stoi(c));
            }
        }
        return stk.top();
    }
};