class Solution {
    unordered_map<Node*, NodeCopy*> nodeToCopy;
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if(!root)
            return nullptr;
        
        if (nodeToCopy.count(root)) {
            return nodeToCopy[root];
        }

        NodeCopy* rootCopy = new NodeCOpy(root->val);
        nodeToCopy[root] = rootCopy;

        rootCopy->left = copyRandomBinaryTree(root->left);
        rootCopy->right = copyRandomBinaryTree(root->right);
        rootCopy->random = copyRandomBinaryTree(root->random);

        return rootCopy;
    }
}