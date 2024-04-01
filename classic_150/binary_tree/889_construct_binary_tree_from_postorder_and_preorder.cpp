#include <vector>
using std::vector;

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

    }
private:
    TreeNode* build(const vector<int>& preorder, int preStart, int preEnd, 
                    const vector<int>& postorder, int postStart, int postEnd){
        // preorder
        // [root][left_child] [right_child]
        // postorder:
        // [left_child][right_child][root]
        
        // basic part, when to stop?
        if (preStart > preEnd || postStart > postEnd)
            return nullptr;


        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        root->left = build();
        root->right = build();

        return root;
    }
};
