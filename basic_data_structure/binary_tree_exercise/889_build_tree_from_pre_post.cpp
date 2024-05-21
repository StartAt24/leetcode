#include "BTree.h"
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

    }
private:
    TreeNode* build(const vector<int>& preorder, int preStart, int preEnd,
                     const vector<int>& postorder, int postStart, int postEnd) {
        // preorder: root, left, right
        // postorder: left, right, root

        if (preStart > preEnd) {
            return nullptr;
        }

        int val = preorder[preStart];
        

    }
};