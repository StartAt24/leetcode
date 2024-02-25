#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;
class Solution {
public:
    int strStr(string haystack, string needle) {
        // KMP algorithm
        // 1. create a partial match table of each index in the string.
        // abcd
        // prefix string: a, ab, abc
        // suffix string: bcd, cd, d
        // the num of this string is the size of the longest overlap string.
        // here it's 0.


    }
private:
    int KMP(string target, string pattern) {
        int i = 0;
        int j = 0;
        while (i < target.size() && j < pattern.size()) {
            // if J equals to -1, it means it need to be rest
            // and the comparasion should start with the next new index;
            if (j == -1 || target[i] == pattern[j]) {
                i++;
                j++;
            } else {
                j = _next[j];
            }
        }
    }

    void GenerateNextArray(string pattern) {
        
    }

    vector<int> _next;
};