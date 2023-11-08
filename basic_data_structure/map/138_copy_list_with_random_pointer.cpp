#include <vector>
#include <map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 建立 node 到node的映射，但是此时 新的链表并没有连接在一起。
        std::unordered_map<Node*, Node*> originalToClone;
        Node* tempHead = head;
        while(tempHead) {
            originalToClone[tempHead] = new Node(tempHead->val);
            tempHead = tempHead->next;
        }

        tempHead = head;
        while(tempHead) {
            if (tempHead->next)
                originalToClone[tempHead]->next = originalToClone[tempHead->next];

            if (tempHead->random)
                originalToClone[tempHead]->random = originalToClone[tempHead->random];
            tempHead = tempHead->next;
        }
    }
};