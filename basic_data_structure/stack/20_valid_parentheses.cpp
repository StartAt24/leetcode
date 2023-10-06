#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for (auto c: s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                char need = _checkMap[c];
                if (!stk.empty() && stk.top() == need)
                    stk.pop();
                else 
                    return false;
            }
        }

        // 检查是否所有括号都匹配完成了。
        // trap here.
        return stk.empty();
    }
private:
    unordered_map<char, char> _checkMap{
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
};