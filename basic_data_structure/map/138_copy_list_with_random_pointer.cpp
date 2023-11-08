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
        if(!head)
            return nullptr;
        Node* tempHead = head;
        Node* dummyHead = new Node(-1);
        Node* p = dummyHead;
        // key is the current index, 
        std::unordered_map<Node*, int> original_list;
        // Key->Val
        std::unordered_map<int, int> relation_list;
        std::unordered_map<int, Node*> node_list;

        // 首先得到每个node及其index
        int idx = 0;
        while(tempHead) {
            original_list.insert({tempHead, idx});
            idx++;
            tempHead = tempHead->next; 
        }

        // 获得node的相对关系 并且创建新的list
        tempHead = head;
        idx = 0;
        while(tempHead) {
            p->next = new Node(tempHead->val);
            node_list.insert({idx, p->next});

            auto targetNode = tempHead->random;

            auto found = original_list.find(targetNode);
            if (found != original_list.end()) {
                relation_list.insert({idx, found->second});
            } else {
                relation_list.insert({idx, -1});
            }

            tempHead = tempHead->next;
            p = p->next;
            idx++;
        }

        p = dummyHead->next;
        idx = 0;
        while(p) {
            int targetNode = relation_list[idx];
            if (targetNode == -1)
                p->random = nullptr;
            else 
                p->random = node_list[idx];

            idx++;
            p = p->next;
        }

        return dummyHead->next; 
    }
};