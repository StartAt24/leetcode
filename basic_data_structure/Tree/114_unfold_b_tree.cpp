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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        
        flatten(root->left);
        flatten(root->right);
        
        // 左右子数 这个时候已经是平的了
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;
        root->right = left;
        // 将原来的右子树接在当前右子树的末端
        TreeNode* p = root;
        while(p->right) {
            p = p->right;
        }
        p->right = right;
    }
};