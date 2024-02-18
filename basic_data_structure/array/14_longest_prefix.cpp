#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        // assume the first string as the common prefix;
        string res = strs[0];
        for (auto s: strs) {
            res = CommonPrefix(res, s);
        }

        return res;
    }
private:
    string CommonPrefix(string s1, string s2) {
        string ret;
        int size1 = s1.size();
        int size2 = s2.size();
        int minSize = std::min(size1, size2);
        for (int i = 0; i < minSize; i++) {
            if(s1[i] == s2[i]) {
                ret += s1[i];
            } else {
                break;
            }
        }

        return ret;
    }
};


// Trie Tree cannot help solve this problem.
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