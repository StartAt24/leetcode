#include <string>
#include <map>
using std::string;
using std::unordered_map;

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
public:
    Trie() {

    }
    
    void insert(string word) {
        _root = insert(_root, word, 0);
    }
    
    // a->b->c->True

    bool search(string word) {
        auto node = getNode(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto node = getNode(prefix);
        return node != nullptr;
    }

private:
    TrieNode* _root = nullptr;

    TrieNode* getNode(string word) {
    #if 0
        TrieNode* node = _root;
        int idx = 0;
        while(node && idx < word.length()) {
            if (!node)
                return nullptr;

            // 结束的条件是 idx == word.length();
            // 即当前的node刚好指向的是 标志着结尾的那个 节点
            node = node->children[word[idx]];
            idx++;
        }

        return node;
    #endif
        TrieNode * node = _root;
        for (auto c: word) {
            if (!node)
                return nullptr;

            node = node->children[c];
        }
        return node;
    }

    TrieNode* insert(TrieNode* node, string word, int i) {
        if (!node) {
            node = new TrieNode();
        }

        if (i == word.length()) {
            node->isEnd = true;
            return node;
        }

        char n = word[i];

        node->children[n] = insert(node->children[n], word, i+1);

        return node;
    }
};