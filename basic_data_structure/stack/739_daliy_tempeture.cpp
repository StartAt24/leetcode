#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk; // store the index
        int size = temperatures.size();
        vector<int> res(size);

        for (int i = size-1; i >= 0; i--) {
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }
            // stk里存储的是 index更靠后的元素。所以应该是 stk.top - index;
            res[i] = stk.empty() ? 0 : (stk.top() - i);
            stk.push(i);
        }

        return res;
    }
};