class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n%2 == 0)
            return {};

        _cache.resize(n+1);
        return build(n);
    }
    
private:
    unordered_map<int, TreeNode*> _m;
    vector<TreeNode*> build(int n) {
        vector<TreeNode*> res;
        if (n == 1) {
            res.push_back(new TreeNode(0));
            return res;
        }

        if (!_cache[n].empty())
            return _cache[n];
            
        // total n's node, except root;
        // and left or right increase with a 2 steps.
        for (int i = 1; i < n; i +=2) {
            int j = n - i - 1;

            vector<TreeNode*> leftSubTrees = build(i);
            vector<TreeNode*> rightSubTrees = build(j);

            for (TreeNode* left : leftSubTrees) {
                for (TreeNode* right : rightSubTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }

        _cache[n] = res;
        return res;
    }

    vector<vector<TreeNode*>> _cache;
};