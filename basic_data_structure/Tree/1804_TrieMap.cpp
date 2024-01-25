#include <map>
#include <vector>
#include <string>

using std::map;
using std::string;
using std::unordered_map;

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    int val = 0;
    bool isEnd = false;
};

class TrieMap{
public:
    void insert(string word, int val) {
        insert(_root, word, 0, val);
    }

    void erase(string word) {

    }

private:
    TrieNode* insert(TrieNode* node, string word, int i, int val) {
        if (!node)
            node = new TrieNode();
        
        if (i == word.length()) {
            node->val = val;
            node->isEnd = true;
            return node;
        }

        node->children[word[i]] = insert(node->children[word[i]], word, i+1, val);

        return node;
    }

private:
    TrieNode* _root = nullptr;
};

class Trie{
public:
    void insert(string word) {

    }

    int countWordsEqualTo(string word) {

    }

    int countWordsStartingWith(string prefix) {

    }

    void erase(string word) {

    }

private:

};