class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);

        if (val > root->val) {
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        } else {
            // the new node should be in the right sub tree;
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};