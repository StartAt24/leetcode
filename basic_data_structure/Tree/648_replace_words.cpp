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

    }

private:
    TrieNode* _root = nullptr;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

    }
};