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
        int begin = left;
        while(left>=1) {
            head = head->next;
            left--;
        }

        ListNode* prev = head;
        head = head->next;
        ListNode* after = head;

        ListNode* last = reverse(head, right - begin + 1);
        prev->next = last; 
        after->next = ;
    }

private:
    ListNode* reverse(ListNode* head, int num) {
        // a->b->c->d
        // d->c->b->a
        // a<-b<-c<-d
        ListNode* p1 = nullptr;
        ListNode* p2 = head;
        ListNode* p3 = head->next;

        while(num) {
            p2->next = p1;
            if (p3 == nullptr)
                break;

            p1 = p2;
            p2 = p3;
            p3 = p3->next;
            num --;
        }

        return p2;
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