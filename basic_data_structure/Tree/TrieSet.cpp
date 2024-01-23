#include <string>
#include <array>
#include <vector>

using std::vector;
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

    string ShortestPrefixOf(string s) {
        if (s.empty())
            return s;
        
        TrieNode* p = _root;
        int i = 0;
        while (p && i < s.size()) {
            if (p->isEnd)
                break;

            int idx = static_cast<int>(s[i]);
            p = p->next[idx];

            i++;
        }

        if (p && p->isEnd) {
            return s.substr(0, i);
        }

        return "";
    }

    string LongestPrefixOf(string s) {
        if (s.empty())
            return s;
        
        TrieNode* p = _root;
        int i = 0;
        int pre_i = 0;
        while (p && i < s.size()) {
            if (p->isEnd) {
                pre_i = i;
            }

            int idx = static_cast<int>(s[i]);
            p = p->next[idx];

            i++;
        }

        if (p && p->isEnd) {
            // 即最长子串为 原始字符串
            pre_i = i;
        }

        return s.substr(0, pre_i);
    }

    // 包含 pattern, pattern里仅支持 “.” 作为通配
    bool Matches(string s) {
        return Matches(_root, s, 0);
    }

    vector<string> KeysWithPrefix(string s) {
        TrieNode* n = GetNode(_root, s);
        // 不存在以当前字符串为 前缀的任何字符串
        if (!n)
            return {};

        vector<string> res;
        // 将 当前的 前缀 s存入，用于组成最终的返回结果。
        Traverse(n, s, res);

        return res;
    }

    // keys with pattern 匹配的字符串长度必须和pattern长度一致
    vector<string> KeysWithPattern(string s) {
        vector<string> res;
        TraverseWithPattern(_root, "", s, 0, res);
        return res;
    }

private:
    bool Matches(TrieNode* node, string pattern, int i) {
        if (!node)
            return false;
        
        if (i == pattern.length())
            return node->isEnd;
        
        char c = pattern[i];
        if (c == '.') {
            // loop all
            for (int i = 0; i < AsiccConst; i++) {
                // 有一个匹配 则返回 True
                if (Matches(node->next[i], pattern, i+1))
                    return true;
            }
        }

        return Matches(node->next[(int)pattern[i]], pattern, i+1)
    }


    void TraverseWithPattern(TrieNode* node, string pre, string pattern, int i, vector<string>& res) {
        // pattern没有跑完 就结束了。
        if (!node)
            return;
        
        // 已经跑完了 pattern，下一步是查看当前是否是一个字符串的end
        if (i == pattern.length()) {
            if (node->isEnd)
                res.push_back(pre);
            return;
        }

        char c = pattern[i];
        int idx = static_cast<char>(pattern[i]);

        // wildcard
        if (c == '.') {
            // 遍历所有的
            for (int i = 0; i < AsiccConst; i++) {
                // 其实这里可以优化的，没必要一直操作 Pre
                pre.append(1, static_cast<char>(i));
                TraverseWithPattern(node->next[i], pre, pattern, i+1, res);
                pre.pop_back();
            }
        } else {
            pre.append(1, pattern[i]);
            TraverseWithPattern(node->next[idx], pre, pattern, i+1, res)
        }

        return;
    }

    void Traverse(TrieNode* node, string pre, vector<string>& res) {
        if (!node)
            return;

        if (node->isEnd) {
            res.push_back(pre);
            // 不能return!! 这个节点是isEnd，同时也可能是其他字符串的组成的节点
            // return;
        }
        
        for (int i = 0; i < AsiccConst; i++) {
            pre.append(1, static_cast<char>(i));
            Traverse(node->next[i], pre, res);
            pre.pop_back();
        }

        return;
    }

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