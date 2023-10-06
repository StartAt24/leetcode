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

        // reset p;
        p = head;
        while(p) {
            ListNode* lastNode = s.top();
            s.pop();
            ListNode* next = p->next;
            // 找到重合的地方
            // 链表为奇数或者偶数的时候均适用
            if (lastNode == next || lastNode->next == next) {
                lastNode->next = nullptr;
                break;                
            }
            p->next = lastNode;
            lastNode->next = next;
            p = next;
        }
    }
};