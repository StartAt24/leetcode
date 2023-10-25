#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> ret(n, 0);
        for (int i = n-1; i >= 0; i--) {
            int count = 0;
            while(!stk.empty() && heights[stk.top()] < heights[i]) {
                stk.pop();
                // pop掉的是比他矮的，并且在下次循环的时候下一个人看到的 已经是上一个人过滤过的。
                count++;
            }
            // now we got the next greater index;
            ret[i] = stk.empty() ? count : count+1;

            stk.push(i);
        }

        return ret;
    }
};