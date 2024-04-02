#include <vector>
#include <string>
#include <map>
using std::string;
using std::unordered_map;
using std::vector;

// Definition for a binary tree node.
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return _result; 
    }
private:
    string serialize(TreeNode* root) {
        if (!root)
            return "#";

        string l = serialize(root->left);
        string r = serialize(root->right);

        string res =  l + "," + r + "," + std::to_string(root->val);
        
        int freq = _duplicateTreeCnts[res];
        if (freq == 1) {
            // first time dup.
            _result.push_back(root);
        }
        _duplicateTreeCnts[res]++;
        return res;
    }

    unordered_map<string, int> _duplicateTreeCnts;
    vector<TreeNode*> _result;
};