#include <iostream>
#include "BTree.h"
using std::cout;
using std::endl;

int count(TreeNode* root) {
    if (!root)
        return 0;

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
}

void traverse(TreeNode* root) {
    if(!root)
        return;
    
    cout << "From" << root <<"to"<< root->left << endl;;
    traverse(root->left);
    cout << "From" << root->left << "to" << root << endl;

    cout << "From" << root << "to" << root->right << endl;
    traverse(root->right);
    cout << "From" << root->right << "to" << root << endl;
}


struct MultiNode{
    int val;
    MultiNode* arr[126]{};
};

void traverse(MultiNode* root) {
    if (!root)
        return;
    for (int i = 0; i < 126; i++) {
        cout << "from" << root << "to" << root->arr[i];
        traverse(root->arr[i]);
        cout << "from" << root->arr[i] << "to" << root;
    }
}