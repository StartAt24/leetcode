struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return nullptr;

        // get target node;
        auto targetNode = GetTargetNode(head, x);
        auto targetValue = targetNode->val;

        // to store the node less than X
        ListNode dummyLeft{};
        dummyLeft.next = head;

        ListNode dummyRight{};

        ListNode* current = head;
        ListNode* tempLeft = &dummyLeft;
        ListNode* tempRight = &dummyRight;

        while(current) {
            if(current->val < x) {
                tempLeft->next = current;
                tempLeft = tempLeft->next;
            } else {
                tempRight->next = current;
                tempRight = tempRight->next;
            }
        }

        auto temp = current->next;
        current->next = nullptr;
        current = temp;

        // contact two list;
        tempLeft->next = dummyRight.next;

        return dummyLeft.next;
    }

private:
    ListNode* GetTargetNode(ListNode* head, int x) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 0 -> 1 -> 2 -> 3 -> 4
        // 

        if (x < 0) {
            int len = -x;
            while(len--) {
                fast = fast->next;
            }
            while(fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        else {
            while (x--) {
                slow = slow->next;
            }
        }

        return slow;
    }
};