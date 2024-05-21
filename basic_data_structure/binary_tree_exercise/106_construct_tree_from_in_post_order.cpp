#include "BTree.h"
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        for (int i = 0; i < size; i++) {
            _position[inorder[i]] = i;
        }
        return build(inorder, 0, size-1, postorder, 0, size-1);
    }
private:
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        // inorder: left root right
        // postorder: left right root
        if (postStart > postEnd) {
            // no root element available;
            return nullptr;
        }
        int val = postorder[postEnd];
        int idx = _position[val];
        TreeNode* n = new TreeNode(val);
        int leftSize = idx - inStart;
        
        n->left = build(inorder, inStart, idx-1, 
                        postorder, postStart, postStart+leftSize-1);

        n->right = build(inorder, idx+1, inEnd, 
                        postorder, postStart+leftSize, postEnd-1);
        return n;
    }
    unordered_map<int, int> _position;
};