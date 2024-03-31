#include <vector>
#include <map>
using std::vector;
using std::unordered_map;
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) {
            _value2Index[inorder[i]] = i;
        }
        TreeNode* root = build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        return root;
    }
private:
    //           inStart    left_size           idx              inEnd
    // inorder:     [       left_child      ]   root  [right_child]
    // 
    //          postStart                                       postEnd
    // postorder:   [       left_child      ] [right_cihld] [root]
    // 


    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        // cannot find root value
        if (postStart > postEnd)
            return nullptr;

        int currentValue = postorder[postEnd];
        TreeNode* n = new TreeNode(currentValue);
        int idx = _value2Index[currentValue];
        int left_size = idx - inStart;

        n->left = build(inorder, inStart, idx-1, postorder, postStart, postStart+left_size-1);
        n->right = build(inorder, idx+1, inEnd, postorder, postStart + left_size, postEnd-1);
        return n;
    }

    unordered_map<int, int> _value2Index;
};