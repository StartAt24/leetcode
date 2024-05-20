#include "BTree.h"

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head)
            return true;
        if (!root)
            return false;
        
        if (head->val == root->val) {
            if (traverse(head, root)) {
                return true;
            }
        }
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
private:
    bool traverse(ListNode* node, TreeNode* treeNode) {
        if (!node)
            return true;

        if (!treeNode) 
            return false;

        if (node->val == treeNode->val)
            return traverse(node->next, treeNode->left) || traverse(node->next, treeNode->right);

        return false;
    }

    ListNode* _head = nullptr;
};