#include <string>
#include <map>

using std::string;
using std::unordered_map;

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class TrieTree {
public:
    TrieTree() {

    }

    void Push(string s) {
        _root = Push(_root, s, 0);
    }

    bool MatchWithPattern(string pattern) {
        return MatchWithPattern(_root, pattern, 0);
    }

private:
    TrieNode* Push(TrieNode* node, string s, int i) {
        if (!node)
            node = new TrieNode();
        
        if (i == s.length()) {
            node->isEnd = true;
            return node;
        }

        node->children[s[i]] = Push(node->children[s[i]], s, i+1);
        return node;
    }

    bool MatchWithPattern(TrieNode* node, string pattern, int i) {
        if (!node)
            return false;

        if (i == pattern.length() && node->isEnd) {
            return true;
        }

        char c = pattern[i];
        if (c == '.') {
            for (const auto& [k, v] : node->children) {
                if (MatchWithPattern(v, pattern, i+1))
                    return true;
            }
        }
        
        return MatchWithPattern(node->children[c], pattern, i+1);
    }

    TrieNode* _root = nullptr;
};

class WordDictionary {
public:
    WordDictionary() {

    }
    
    void addWord(string word) {
        tree.Push(word);
    }
    
    bool search(string word) {
        return tree.MatchWithPattern(word);
    }
private:
    TrieTree tree;
};