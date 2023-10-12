#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> stk;
        int maxLen = 0;
        while(1) {
            int idx = input.find_first_of('\n');
            // split with \n so the string would look like this "\txxx\t\txxx"
            if (idx != std::string::npos) {
                // first string
                string temp = input.substr(0, idx);
                input = input.substr(idx+1);
                int level = temp.find_last_of('\t') + 1;

                // 让栈只保留当前目录的父路径
                while (level < stk.size()) {
                    stk.pop();
                }

                // 当前目录或者文本入栈
                stk.push(temp.substr(level));

                if (temp.find('.') != string::npos) {
                    stack<string> stk_cpy = stk;
                    int sum = 0;
                    while(!stk_cpy.empty()) {
                        sum += stk_cpy.top().size();
                        stk_cpy.pop();
                    }

                    // 加上所有的 '/'
                    sum += stk.size()-1;
                    maxLen = std::max(sum, maxLen);
                }

            }
        }
    }
};