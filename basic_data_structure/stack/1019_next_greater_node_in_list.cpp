#include <vector>
#include <stack>
#include <map>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // it's a linked list so one way
        vector<int> listVec;
        while(head) {
            listVec.push_back(head->val);
            head = head->next;
        }

        stack<int> stk;
        int n = listVec.size();
        vector<int> ret(n, 0);
        for (int i = n-1; i >=0; i--) {
            while(!stk.empty() && stk.top() <= listVec[i]) {
                stk.pop();
            }
            ret[i] = stk.empty() ? 0 : stk.top();
            stk.push(listVec[i]);
        }

        return ret;
    }
};