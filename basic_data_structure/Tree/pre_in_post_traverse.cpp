// print level of a tree
#include "BTree.h"
#include <iostream>

using std::count;
using std::endl;

void PrintLevel(TreeNode* n, int l) {
    if (!n)
        return;

    cout << l + 1 << endl;
    PrintLevel(n->left, l+1);
    PrintLevel(n->right, l+1);
}

// print level of it's left and right

int PrintChildLevel(TreeNode* n) {
    if (!n)
        return 0;
    int left = PrintChildLevel(n->left);
    int right = PrintChildLevel(n->right);
    cout << left << right << endl;

    return left+right+1;
}