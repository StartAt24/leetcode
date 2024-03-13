#include "BTree.h"
#include <vector>

using std::vector;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // pre order
        int lastElement = preorder.back();
        TreeNode* lastOne = new TreeNode(lastElement);



    }
};