#include <map>
#include <vector>
#include <string>

using std::map;
using std::string;
using std::vector;
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
        auto n = count(word);
        n--;
        if (n == 0) {
            erase(_root, word, 0);
        } else {
            insert(word, n);
        }
    }

    vector<string> wordsStartWith(string prefix) {
        vector<string> res;
        auto n = getNode(_root, prefix);
        wordsStartWith(n, prefix, res);
        return res;
    }

    bool contains(string word) {
        TrieNode* n = getNode(_root, word);
        return n && n->isEnd;
    }

    int count(string word) {
        if (!contains)
            return 0;

        return getNode(_root, word)->val;
    }

private:
    void wordsStartWith(TrieNode* node, string prefix, vector<string>& res) {
        // 到了末端了，可以return了
        if (!node)
            return;

        if (node->isEnd) {
            res.push_back(prefix);
        }

        for (const auto& [k,v] : node->children) {
            string path = prefix + k;
            wordsStartWith(v, path, res);
        }

        return;
    }

    TrieNode* erase(TrieNode* node, string word, int i) {
        if (i == word.length()) {
            node->isEnd = false;
        } else {
            // need to handle it's children first, then handle itself 后续位置处理自己
            node->children[word[i]] = erase(node->children[word[i]], word, i+1);
        }

        for (const auto& [k, v] : node->children) {
            if (v) {
                return node;
            }
        }
        // 后序位置， 递归路径上的节点可能要被清理。
        // 比如 一个Trie里有 ab 和 abcd, remove abcd时, c和 d都需要被清理掉 ,但是 ab不能被remove.
        if (node->isEnd)
            return node;

        return nullptr;
    }

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

    TrieNode* getNode(TrieNode* node, string word) {
        for (auto c: word) {
            if (!node)
                return nullptr;

            node = node->children[c];
        }

        return node;
    }

private:
    TrieNode* _root = nullptr;
};

class Trie{
public:
    void insert(string word) {
        _trie.insert(word, 1);
    }

    int countWordsEqualTo(string word) {
        return _trie.count(word);
    }

    int countWordsStartingWith(string prefix) {
        auto words = _trie.wordsStartWith(prefix);
        int res = 0;
        for (auto w : words) {
            res += _trie.count(w);
        }
        return res;
    }

    void erase(string word) {
        _trie.erase(word);
    }

private:
    TrieMap _trie;
};