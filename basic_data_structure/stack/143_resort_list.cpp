#include "../list/common.hpp"
#include <stack>

class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* p = head;

        while(p) {
            s.push(p);
            p = p->next;
        }
        // 4个的话 需要循环两次
        // 3个的话 需要循环1一次？
        ListNode* front = head;
        ListNode* back = s.top();
        ListNode dummyHead;
        ListNode* pDummy = &dummyHead;

        int size = s.size();
        while() {

        }

        pDummy->next = nullptr;
    }
};