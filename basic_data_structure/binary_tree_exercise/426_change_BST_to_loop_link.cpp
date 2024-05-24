class Solution {
public:
    // 定义：输入一棵 BST，返回该 BST 改造成的环形链表的头结点
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return nullptr;

        // convert left node first.
        // convert right node then,
        // connet left root and right.

        Node* leftHead = treeToDoublyList(root->left);
        Node* rightHead = treeToDoublyList(root->right);
        Node* leftTail = nullptr, *rightTail = nullptr;

        // head merge into left 
        if (leftHead) {
            leftTail = leftHead->left;
            root->left = leftTail;
            leftTail->right = root;
        } else {
            leftTail = leftHead = root;
        }

        // head merge into right
        if (rightHead) {
            rightTail = rightHead->left;
            root->right = rightHead;
            rightHead->left = root;
        } else {
            rightTail = rightHead = root;
        }

        // connect two big loop;
        leftHead->left = rightTail;
        rightTail->right = leftHead;

        return leftHead;
    }
}