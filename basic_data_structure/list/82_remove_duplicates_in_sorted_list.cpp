struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;
        
        // dummy head!!!
        ListNode dummyHead{-1};
        ListNode* slow = &dummyHead, *fast = head;
        dummyHead.next = slow;
        // it's a sorted list;
        while(fast){
            // skip duplicate element 
            if (fast->next && fast->val == fast->next->val) {
                while(fast->next && fast->val == fast->next->val) {
                    fast = fast->next;
                }
                // next element, but we don't know if it's a duplicate one.
                // it will be check in the next loop;
                fast = fast->next;
            } else {
                // not duplicate
                // 1. fast is the last one
                // 2. fast is not duplicate
                slow->next = fast;
                slow = slow->next;
                fast = fast->next;
            }
        }

        // detach the last one;
        slow->next = nullptr;

        return dummyHead.next;
    }
};