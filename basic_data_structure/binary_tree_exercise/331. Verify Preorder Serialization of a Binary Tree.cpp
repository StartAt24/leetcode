#include "BTree.h"

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        vector<string> nodes;
        string node;
        while(getline(ss, node, ',')) {
            nodes.push_back(node);
        }
        
        // this preorder will automatically remove and only left the right part.
        return deserialize(nodes) && nodes.empty();
    }
private:
    bool deserialize(vector<string>& nodes) {
        if (nodes.empty()) {
            // ?
            return false;
        }

        string first = node.front();
        nodes.pop_front();
        if (first == "#") return true;

        // deserialize left and right subtree;
        return deserialize(nodes) && deserialize(nodes);
    }
};