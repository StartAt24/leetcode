#include <iostream>
#include <vector>
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
        auto targetValue = x;

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
            auto temp = current->next;
            current->next = nullptr;
            current = temp;
        }

        // contact two list;
        tempLeft->next = dummyRight.next;

        return dummyLeft.next;
    }
};

ListNode* MakeList(const std::vector<int>& arr) {
    ListNode head, *current = &head;

    for(auto i : arr) {
        current->next = new ListNode(i);
        current = current->next;
    }
    return head.next; 
}

void PrintList(const ListNode* head){
    while(head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> s = {2, 1};
    ListNode* head = MakeList(s);
    Solution sol;
    auto result = sol.partition(head, 2);
    PrintList(result);
    return 0;
}