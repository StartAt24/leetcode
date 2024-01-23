#include <map>
#include <optional>

using std::map;

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    optional<int> val = std::nullopt;
    bool isEnd = false;

    TrieNode(int v) {
        val = v;
    }
};

class TrieMap{
    public:

    private:
        TrieNode* _root;
};