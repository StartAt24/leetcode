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

string SEP = ",";
string NULLNode = "#";
string serializeLayers(TreeNode* root) {
    if(!root)
        return "";
    stringstream ss;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (!cur) {
            ss << NULLNode << SEP;
            continue;
        }

        ss << cur->val << SEP; 
        q.push(cur->left);
        q.push(cur->right);
    }
    return ss.str();
}

TreeNode* deserializeLayers(string data) {
    if (data.empty())
        return nullptr;
    vector<string> nodes;
    stringstream ss(data);
    string item;
    while(getline(ss, item, ',')) {
        nodes.push_back(item);
    }

    auto root = new TreeNode(stoi(nodes[0]));

    queue<TreeNode*> q;
    q.push(root);

    for (int i = 1; i < nodes.size();) {
        TreeNode* parent = q.front();
        q.pop();

        string left = nodes[i++];
        if (left != NULLNode) {
            parent->left = new TreeNode(stoi(left));
            q.push(parent->left);
        } else {
            parent->left = nullptr;
        }

        string right = nodes[i++];
        if (right != NULLNode) {
            parent->left = new TreeNode(stoi(right));
            q.push(parent->right);
        } else {
            parent->right = nullptr;
        }
    }

    return root;
}