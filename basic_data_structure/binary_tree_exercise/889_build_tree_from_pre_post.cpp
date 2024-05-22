#include "BTree.h"
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int s = preorder.size();
        for(int i = 0; i < s; i++) {
            _position[postorder[i]] = i;
        }
    }
private:
    unordered_map<int, int> _position;

    TreeNode* build(const vector<int>& preorder, int preStart, int preEnd,
                     const vector<int>& postorder, int postStart, int postEnd) {
        //                next_root
        // preorder: 
        //      left_root
        // root [.....left.....][......right......]
        //              
        // postorder: 
        //     left_size    left_root
        // [.......left.......][........right......]root

        if (preStart > preEnd) {
            return nullptr;
        }

        // we need to modify `preStart + 1` so here we need to return ealier.
        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        int val = preorder[preStart];
        TreeNode* n = new TreeNode(val);

        int leftRoot = preorder[preStart+1];
        int idx = _position[leftRoot];
        int leftSize = idx - postStart + 1;

        n->left = build(preorder, preStart+1, preStart+leftSize,
                        postorder, postStart, idx);
        n->right = build(preorder, preStart+leftSize+1, preEnd,
                        postorder, idx+1, postEnd-1);
        return n; 
    }
};