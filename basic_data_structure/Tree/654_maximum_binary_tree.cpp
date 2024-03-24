#include <vector>
#include <algorithm>
using namespace std;
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
            
        auto maxNum = std::max_element(nums.begin(), nums.end());
        auto prefixArr = vector<int>(nums.begin(), maxNum);
        auto suffixArr = vector<int>(maxNum+1, nums.end());
        // recursively construct two parts.
        TreeNode* leftNode = constructMaximumBinaryTree(prefixArr);
        TreeNode* rightNode = constructMaximumBinaryTree(suffixArr);

        TreeNode* newNode = new TreeNode(*maxNum);
        newNode->left = leftNode;
        newNode->right = rightNode;
        return newNode;
    }
};