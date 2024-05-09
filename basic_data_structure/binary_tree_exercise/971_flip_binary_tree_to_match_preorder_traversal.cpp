#include "BTree.h"

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        _voyage = voyage;
    }
private:
    void traverse(TreeNode* n) {
        if (!n)
            return;
        
        if (n->val != _vogage[_idx]){
            _match = false;
            return;
        }

        if (n->left && )
        
    }
    bool _match = true;
    int _idx = 0;
    vector<int> _voyage;
};