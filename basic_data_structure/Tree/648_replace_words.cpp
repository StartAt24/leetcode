#include <string>
#include <map>
#include <vector>

using std::vector;
using std::string;
using std::unordered_map;

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class TrieTree{
public:
    void Push(string s) {
        _root = Push(_root, s, 0);
    }

    string ShortestPrefix(string s) {
        TrieNode* node = _root;
        int i = 0;
        for(auto c: s) {
            if (!node)
                break;

            if (node->isEnd) {
                break;
            }

            node = node->children[c];
            i++;
        }

        if (!node)
            return "";

        return s.substr(0, i);
    }

private:
    TrieNode* Push(TrieNode* node, string s, int i) {
        if (!node) {
            node = new TrieNode();
        }

        if (i == s.length()) {
            node->isEnd = true;
            return node;
        }

        node->children[s[i]] = Push(node->children[s[i]], s, i+1);

        return node;
    }

private:
    TrieNode* _root = nullptr;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieTree t;
        for (auto s: dictionary) {
            t.Push(s);
        }

        string temp;
        string result;
        sentence.append(1, ' ');
        for(auto c: sentence) {
            if (c != ' '){
                temp.append(1, c);
            }else {
                string prefix = t.ShortestPrefix(temp);
                if (prefix.empty()) {
                    result.append(temp);
                }else {
                    result.append(prefix);
                }
                result.append(1, ' ');
                temp = "";
            }
        }
        result.pop_back();

        return result;
    }
};