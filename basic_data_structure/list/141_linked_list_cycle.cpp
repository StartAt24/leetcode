
//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(1) {
            if (fast == nullptr)
                return false;
            slow = slow->next;
            if (fast->next)
                fast = fast->next->next;
            else 
                return false;
            
            if (slow == fast)
                return true;
        }
        return false;
    }
};