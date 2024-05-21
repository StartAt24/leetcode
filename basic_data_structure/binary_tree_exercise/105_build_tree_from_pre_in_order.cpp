#include "BTree.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // cache position;
        for(int i = 0; i < inorder.size(); i++) {
            _position[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
    TreeNode* buildTree(const vector<int>& preorder, int preBegin, int preEnd, 
                    const vector<int>& inorder, int inBegin, int inEnd ) {
        if(preBegin > preEnd) {
            return nullptr;
        }

        // preorder: root left right
        // inorder: left root right;
        int nodeVal = preorder[preBegin];
        TreeNode* newNode = new TreeNode(nodeVal);
        int idx = _position[nodeVal];
        int leftSize = idx - inBegin;

        newNode->left = buildTree(preorder, preBegin+1, preBegin+leftSize, 
                                inorder, inBegin, idx - 1);
        newNode->right = buildTree(preorder, preBegin+leftSize+1, preEnd, 
                                inorder, idx+1, inEnd);

        return newNode;
    }

    unordered_map<int, int> _position;
};