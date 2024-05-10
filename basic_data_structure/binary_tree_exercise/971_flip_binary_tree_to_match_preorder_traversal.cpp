#include "BTree.h"

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        _voyage = voyage;
        traverse(root);
        if(_match) {
            return _res;
        } else {
            return {-1};
        }
    }
private:
    void traverse(TreeNode* n) {
        if (!n)
            return;
        
        if (n->val != _voyage[_idx]){
            _match = false;
            return;
        }

        _idx++;
        if (n->left && n->left->val != _voyage[_idx]) {
            auto temp = n->right;
            n->right = n->left;
            n->left = temp;
            _res.push_back(n->val);
        }
        traverse(n->left);
        traverse(n->right);
    }
    bool _match = true;
    int _idx = 0;
    vector<int> _res;
    vector<int> _voyage;
};