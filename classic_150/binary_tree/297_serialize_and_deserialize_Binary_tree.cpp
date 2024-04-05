#include <string>
#include <sstream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "#";
        string leftTreeStr = serialize(root->left);
        string rightTreeStr = serialize(root->right);

        return std::to_string(root->val) + "," + leftTreeStr + "," + rightTreeStr;
    }

    void serialize2(TreeNode* root, string& res) {
        if (!root) {
            res += _nullChild + _delim;
        }

        res += std::to_string(root->val) + _delim;
        serialize2(root->left, res);
        serialize2(root->right, res);
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // first need to get the element value from this string;
        sstream s(data);
        vector<string> nodes;
        string element;
        while(std::getline(s, element, ',')) {
            nodes.push_back(element);
        }
        return build(nodes);
    }
private:
    // you can build a unique tree from a pre/post order with null pointer;
    TreeNode* build(vector<string>& nodeVals) {
        if (nodeVals.empty())
            return nullptr;

        string root = nodeVals.front();
        nodeVals.erase(nodeVals.begin());
        if (root == "#")
            return nullptr;
        
        TreeNode* n = new TreeNode(stoi(root));
        // 这里非常巧妙，左子树的递归已经把左子树的所有元素清空完了。下面再交给右子树
        n->left = build(nodeVals);
        n->right = build(nodeVals);
        return n;
    }

    const string _delim = ",";
    const string _nullChild = "#";
};

#include <queue>
// 层序遍历
void traverse(TreeNode* n) {
    if (!n)
        return;
    queue<TreeNode*> q;
    q.push(n);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        // 
        if (cur->left) {
            q.push(cur->left);
        }
        if (cur->right) {
            q.push(cur->right);
        }
    }
}

// 这样的遍历会将 nullptr也加入到 queue中
void traverseWithNullptr(TreeNode* n) {
    if (!n)
        return;
    queue<TreeNode*> q;
    q.push(n);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        if (!cur)
            continue;
        
        q.push(cur->left);
        q.push(cur->right);
    }
}