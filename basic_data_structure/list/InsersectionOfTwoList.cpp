struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;
        
        ListNode* abPointer = headA;
        ListNode* baPointer = headB;

        while(abPointer != baPointer) {
            if(!abPointer) {
                abPointer = headB;
            } else {
                abPointer = abPointer->next;
            }


            if (!baPointer) {
                baPointer = headA;
            } else {
                baPointer = baPointer->next;
            }
        }
        return abPointer;
    }
};