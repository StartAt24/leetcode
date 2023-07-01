struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return nullptr;

        ListNode dummyHead;
        dummyHead.next = head;
        // need to find N+1 element from end;
        // N+1 -> N -> N-1
        //  N+1 -> N-1
        ListNode* NPlus1 = findNthFromEnd(&dummyHead, n+1);
        if (!NPlus1)
            return nullptr;

        auto removed = NPlus1->next;
        NPlus1->next = NPlus1->next->next;
        removed->next = nullptr;


        return dummyHead.next; 
    }

    ListNode* findNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;

        while(n--) {
            if (!fast)
                return nullptr;
            fast = fast->next;
        }

        while(1) {
            if (!fast)
                return slow;
            fast = fast->next;
            slow = slow->next;
        }
    }
};