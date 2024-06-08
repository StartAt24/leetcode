#include "BTree.h"
#include <string>
using namespace std;

string res;

// we don't need to manually take care of the last ","
// we can do it later in the deserialize function.
void Serialize(TreeNode* root) {
    if (!root) {
        res += "#";
        res += ",";
        return;
    }

    res += to_string(root->val) + ",";
    Serialize(root->left);
    Serialize(root->right);
}


TreeNode* Deserialize(const vector<int>& nodes) {
    if (nodes.empty())
        return nullptr;
    
    int val = nodes[i];
    TreeNode* n = nullptr;
    if (val != -1) {
        n = new TreeNode(val);
    }

    nodes.erase(nodes.begin());

    n->left = Deserialize(nodes);
    n->right = Deserialize(nodes);

    return n;
}
