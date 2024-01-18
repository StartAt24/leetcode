#include <string>
#include <array>

using std::string;
using std::array;

constexpr int AsiccConst = 256;

struct TrieNode {
    // 多叉树
    array<TrieNode*, AsiccConst> next;
    // 用来标识 是公共前缀还是一个字符串
    bool isEnd = false;
};


class TrieSet{
public:
    TrieSet() = default;
    // add
    bool Add(string s) {
        if (s.empty() || Contains(s))
            return false;

        _root = Add(_root, s, 0);
        _size++; 
        return true;
    }

    bool Remove(string s) {
        if (!Contains(s)) {
            return false;
        }

        _root = Remove(_root, s, 0);
        _size--;
        return true;
    }

    bool Contains(string s) {
        TrieNode* n = GetNode(_root, s);

        if (n && n->isEnd)
            return true;

        return false;
    }

private:
    TrieNode* Add(TrieNode* node, string s, int idx) {
        if (!node) {
            // 这里的 node并没有存放任何信息，而是用node的指针来表明指向该node的 值存在
           node = new TrieNode();
        }

        if(idx = s.size()) {
            node->isEnd = true;
            return node;
        }

        int idx = static_cast<int>(s[idx]);
        node->next[idx] = Add(node->next[idx], s, idx+1);

        return node;
    }

    TrieNode* Remove(TrieNode* node, string s, int idx) {
        if (idx == s.size()) {
            node->isEnd = false;
        }
        else {
            int charIdx = static_cast<int>(s[idx]);
            node->next[charIdx] = Remove(node->next[charIdx], s, idx+1);
        }

        // 如果当前节点仍然是一个标志位的话，则不删除
        if (node->isEnd)
            return node;
        
        // 如果当前节点仍然是某个字符串的一环的话，则也不删除
        for (auto p: node->next) {
            if (p)
                return node;
        }

        return nullptr;
    }

    TrieNode* GetNode(TrieNode* startPoint, string s) {
        TrieNode* n = startPoint;

        for (auto c: s) {
            if (n->next[c] == nullptr)
                return nullptr;

            n = n->next[c];
        }

        return n;
    }

private:
    TrieNode* _root = nullptr;
    int _size = 0;
};