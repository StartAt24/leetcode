struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* slow = head, *fast = head;
        while(1) {
            if (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
            else {
                return slow;
            }
        }
    }
};