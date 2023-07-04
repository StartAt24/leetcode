struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head)
            return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(k--){
            if (fast)
                fast = fast->next;
            else 
                return nullptr;
        }

        while(1){
            if (!fast)
                return slow;
            fast = fast->next;
            slow = slow->next;
        }
    }
};