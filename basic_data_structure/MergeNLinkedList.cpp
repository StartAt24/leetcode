struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto NodeCompare = [](const ListNode* left, const ListNode* right){
            return left->val > right->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(NodeCompare)> minHeap(NodeCompare);

        for(auto list: lists){
            while(list) {
                minHeap.push(list);
                auto temp = list->next;
                // !!!! don't forget to detach each node!
                list->next = nullptr;
                list = temp;
            }
        }
        ListNode dummyHead{};
        ListNode* cursor = &dummyHead;
        while(!minHeap.empty()){
            cursor->next = minHeap.top();
            minHeap.pop();
            cursor = cursor->next;
        }
        return dummyHead.next;
    }
};