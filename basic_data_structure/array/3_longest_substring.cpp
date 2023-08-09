#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        map<char, int> window;
        int maxlen = 0;
        while(right<s.size()) {
            char a = s[right];
            right++;
            window[a]++;

            // if found repeat increase left bound;
            // while 存在重复字串，则无限缩小
            while(window[a] > 1) {
                char d = s[left];
                left++;
                window[d]--;
            }
            // for case like abcc
            // we already get the longest string when right point to the first c;
            // at this point there is no repeat string.
            maxlen = std::max(maxlen, right-left);
        }
        return maxlen;
    }
};