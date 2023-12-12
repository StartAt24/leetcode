// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

    }
};

class Test{
public:
    ListNode* reverse(ListNode* head) {
        // a->b->c->d
        // d->c->b->a
        // a<-b<-c<-d
        ListNode* p1 = nullptr;
        ListNode* p2 = head;
        ListNode* p3 = head->next;

        while(1) {
            p2->next = p1;
            if (p3 == nullptr)
                break;

            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }

        return p2;
    }

};