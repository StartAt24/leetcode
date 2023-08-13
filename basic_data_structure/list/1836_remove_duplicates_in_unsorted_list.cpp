#include <map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if (!head || !head->next)
            return head;
        unordered_map<int, int> cache;
        ListNode* p = head;
        while(p) {
            cache[p->val]++;
            p = p->next;
        }

        ListNode dummyHead;
        ListNode* pDummyHead = &dummyHead;
        pDummyHead->next = head;
        p = pDummyHead;

        while(p) {
            ListNode* unique = p->next;
            while(unique && cache[unique->val] > 1) {
                unique = unique->next;
            }
            p->next = unique;
            p = p->next;
        }
        return pDummyHead->next; 
    }
};