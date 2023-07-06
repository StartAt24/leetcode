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

        ListNode* cursor = head;
        ListNode dummyHead(-1000);
        ListNode *slow = &dummyHead;

        while(1) {
            if (!cursor)
                break;
            if (cursor->val != slow->val) {
                slow->next = cursor;
                cursor = cursor->next; 
                slow = slow->next;
                // disconnect from next;
                slow->next = nullptr;
            }
            else {
                cursor = cursor->next;
            }
        }
        return dummyHead.next;
    }
};