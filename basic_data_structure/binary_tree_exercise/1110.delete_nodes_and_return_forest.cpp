class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root)
            return nullptr;
        
        for (auto i : to_delete) {
            _to_delete.insert(i);
        }

        doDelete(root, false);

        return res;
    }
private:
    TreeNode* doDelete(TreeNode* root, bool hasParent) {
        if(!root)
            return nullptr;
        
        bool needToDelete = _to_delete.count(root->val);
        if (!needToDelete && !hasParent) {
            _res.push_back(root);
        }

        root->left = doDelete(root->left, !needToDelete);
        root->right = doDelete(root->right, !needToDelete);

        return needToDelete ? nullptr : root;
    }

    vector<TreeNode*> _res;
    unordered_set<int> _to_delete;
};