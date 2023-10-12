#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> stk;
        int maxLen = 0;
        auto parts = SplitStr(input, '\n');
        for (auto part : parts) {
            // split with \n so the string would look like this "\txxx\t\txxx"
            // first string
            int level = part.find_last_of('\t') + 1;

            // 让栈只保留当前目录的父路径
            while (level < stk.size()) {
                stk.pop();
            }

            // 当前目录或者文本入栈
            stk.push(part);

            if (part.find('.') != string::npos) {
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
        return maxLen;
    }
private:
    vector<string> SplitStr(string input, char c) {
        vector<string> ret;
        while(1) {
            int pos = input.find_first_of(c);
            if (pos != string::npos) {
                ret.push_back(input.substr(0, pos));
                input = input.substr(pos+1);
            } else {
                // 没有 \n了 可能是
                if (!input.empty()) {
                    ret.push_back(input);
                }
                break;
            }
        }
        return ret;
    }
};