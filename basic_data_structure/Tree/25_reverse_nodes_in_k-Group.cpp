//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return nullptr;
        
        ListNode* a = head, *b = head;
        // find end node;
        for (int i = 0; i < k; i++) {
            // less than k element;
            if (!b) 
                return head;
            b = b->next;
        }

        ListNode* newHead = reverseGroup(a, b);
        a->next = reverseKGroup(b, k);
        return newHead;
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr, *cur = nullptr, *next = nullptr;
        cur = head;
        next = head;
        while(cur != nullptr) {
            next = cur->next;
            // reverse current node;
            cur->next = prev;
            // update node pointer;
            prev = cur;
            cur = next;
        }
        // 返回反转后的头结点
        // 这个时候 cur == nullptr;
        return prev;
    }

    // reverse [a, b)
    ListNode* reverseGroup(ListNode* a, ListNode* b) {
        ListNode* prev = nullptr, *cur = nullptr, *next = nullptr;
        cur = a;
        next = a;
        while(cur != b) {
            next = cur->next;
            // reverse current node;
            cur->next = prev;
            // update node pointer;
            prev = cur;
            cur = next;
        }
        // 返回反转后的头结点
        // 这个时候 cur == nullptr;
        return prev;
    }
};