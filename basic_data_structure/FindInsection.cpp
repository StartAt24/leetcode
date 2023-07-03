struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next; 
            fast = fast->next->next;
            if (fast == slow)
                break;
        }

        // no loop in this list;
        if (!fast || !fast->next)
            return nullptr;
        
        slow = head;
        while(1) {
            slow = slow->next;
            fast = fast->next;
            if (slow == fast)
                break;
        }

        return slow;
    }
};