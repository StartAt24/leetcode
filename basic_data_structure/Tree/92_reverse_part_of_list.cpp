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
        if (left == 1) {
            return recursiveReverse(head, right);
        }

        // 一路前进到 反转的起点，并且触发基础条件里的 recursive
        head->next = reverseBetween(head->next, left-1, right-1);

        return head;
    }

    // pre commit
private:
    // reverse first Ns elements;
    ListNode* recursiveReverse(ListNode* head, int n) {
        if (n == 1) {
            _seccessor = head->next;
            return head;
        }

        ListNode* lastOne = recursiveReverse(head->next, n-1);

        head->next->next = head;
        head->next = _seccessor;

        return lastOne;
    }

    ListNode* _seccessor = nullptr;
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
private:
    ListNode* recursiveReverse(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* lastOne = recursiveReverse(head->next);
        // a->b(->null)<-c<-d

        head->next->next = head;
        // a<-b<-c<-d;

        head->next = nullptr;
        // nullptr<-a<-b<-c<-d;

        return lastOne;
    }
};