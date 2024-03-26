#include "BTree.h"
#include <map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // pre order
        for(int i = 0; i < inorder.size(); i++) {
            _indexOfValue[inorder[i]] = i;
        }

    }
private:
    TreeNode* buildTreeInternal(vector<int>& preorder, int preStart, int preEnd,
                                vector<int>& inorder, int inStart, int inEnd)
    {
        // 终止条件？
        // 这种情况下，证明已经没有rootValue的值了。 只有这种情况可以break.
        // 表面这个根的值已经取不出来了。
        if (preStart>preEnd)
            return nullptr;
        // preorder: root [left_child] [right_child]
        // inorder: [left_child] root [right_child]
        int rootVal = preorder[preStart];
        TreeNode* n = new TreeNode(rootVal);
        int index = _indexOfValue(rootVal);
        int leftSize = index - inStart;
        TreeNode* left = buildTreeInternal(preorder, preStart+1, preStart+leftSize, inorder, inStart, index-1);
        TreeNode* right = buildTreeInternal(preorder, preStart+leftSize+1, preEnd, inorder, index+1, inEnd);
        n->left = left;
        n->right = right;
        return n;
    }
    unordered_map<int, int> _indexOfValue;
};