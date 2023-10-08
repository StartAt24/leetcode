#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        // need 记录需要有括号的数量
        int res = 0, need = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                need += 2;
                if (need % 2 == 1) {
                    // 插入一个右边括号
                    res++;
                    // 对右括号的需求-1
                    need--;
                }
            }

            if (s[i] == ')') {
                need--;
                // 说明 )太多了
                if (need == -1) {
                    // 需要一个左括号
                    res++;
                    // 同时重置 need 为 1 因为左括号一对二的原因，右括号又需要一个
                    need = 1;
                }
            }
        }

        return res + need;
    }
};