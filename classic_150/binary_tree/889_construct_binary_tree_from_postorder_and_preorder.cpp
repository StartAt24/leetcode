#include <vector>
#include <map>
using std::unordered_map;
using std::vector;

//  Definition for a binary tree node.
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            int val = postorder[i];
            _indexOfValue[val] = i;
        }
    }
private:
    unordered_map<int, int> _indexOfValue;
    TreeNode* build(const vector<int>& preorder, int preStart, int preEnd, 
                    const vector<int>& postorder, int postStart, int postEnd){
        // preorder
        // preStart   leftRootValue              preStart+ left_size            preEnd
        // [   root     ][           left_child        ][              right_child]
        // postorder:
        // postStart                    leftRootValue
        //                                 index                                   postEnd
        // [            left_child          ][         right_child             ][root]
        
        // basic part, when to stop?
        if (preStart > preEnd || postStart > postEnd)
            return nullptr;

        // 这个时候就不能再往后吗走了，因为后面的涉及到+1的操作
        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int leftRootVal = preorder[preStart+1];
        int idx = _indexOfValue[leftRootVal];
        int leftSize = idx - postStart + 1;


        root->left = build(preorder, preStart+1, preStart+leftSize, postorder, postStart, index);
        root->right = build(preorder, preStart+leftSize+1, preEnd, postorder, index+1, postEnd-1);


        return root;
    }
};
