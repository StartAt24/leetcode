#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

    }
};

struct TrieNode{
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class TrieTree{
public:
    bool Insert(string s) {
        _root = Insert(_root, s, 0);
        return true;
    };

    string LongestPrefix() {
        
    }

private:
    TrieNode* _root = nullptr;

private:
    void LongestPrefix(TrieNode* n, string path, int i) {
        
    }

    bool Contains(string s) {
        TrieNode* n = GetNode(s);
        return n && n->isEnd;
    }

    TrieNode* GetNode(string s) {
        TrieNode* n = _root;
        for (auto c : s) {
            n = n->children[c];
            if (!n)
                return nullptr;
        }

        return n;
    }


    TrieNode* Insert(TrieNode* n, string s, int i) {
        if (n == nullptr) {
            n = new TrieNode();
        }

        if (i == s.size()) {
            n->isEnd = true;
            return n;
        }
        int idx = static_cast<int>(s[i]);
        n->children[idx] = Insert(n->children[idx], s, i+1);

        return n;
    }
};