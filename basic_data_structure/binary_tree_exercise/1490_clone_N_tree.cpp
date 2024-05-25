#include "BTree.h"

struct Node{
    int val;
    vector<Node*> children;
};

class Solution {
public:
    Node* cloneTree(Node* root) {
        if(!root)
            return nullptr;
        
        Node* clonedOne = new Node(root->val);
        int childrenCount = root->children.size();
        clonedOne->children.resize(childrenCount);

        for (int i = 0; i < childrenCount; i++) {
            clonedOne->children[i] = cloneTree(root->children[i]);
        }
        return clonedOne;
    }
};