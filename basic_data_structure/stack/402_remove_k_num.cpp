#include <stack>
#include <vector>
#include <string>

using namespace std;

// 为了让数字最小，则
// 1.让数字从头到尾变成单调递增
// 2.如果还有次数的话，则从末尾开始移除大的数字。
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        
        stack<char> stk;
        // 递增的意思是把 比第一个数字大的数字都移除
        // 这个其实结果是 pre
        for(int i = 0; i < num.size(); i++) {
            while(!stk.empty() && stk.top() > num[i] && k > 0)  {
                stk.pop();
                k--;
            }
            // 防止0出现在首位  
            if(stk.empty() && num[i] == '0') {
                continue;
            }

            stk.push(num[i]);
        }

        // k不为0 则从末尾再删除一些元素
        while(!stk.empty() && k>0) {
            stk.pop();
            k--;
        }

        //NB! 此时stack中的元素从小到大排列，但是于元素出入栈顺序是相反的！

        if (stk.empty())
            return "0";

        string ans = "";
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};