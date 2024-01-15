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

    }

    bool Remove(string s) {

    }

    bool Contains(string s) {

    }

private:
    TrieNode _root = nullptr;
};