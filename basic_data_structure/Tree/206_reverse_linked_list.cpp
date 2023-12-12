#include <vector>
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
    ListNode* reverseList(ListNode* head) {

    }

private:
    void reverseList(ListNode* n1, ListNode* n2) {
        if (n2->next == nullptr) {
            n2->next = n1;
            return;
        }

        return reverseList(n2, n2->next);
    }
};