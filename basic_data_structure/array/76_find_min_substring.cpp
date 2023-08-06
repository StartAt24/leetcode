#include <string>
#include <map>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> need, window;
        for (auto c: t) {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0, targetSize = need.size();
        int start = 0, len = std::numeric_limits<int>::max();

        // record of start index and len;
        int strSize = s.size();
        while (right < strSize) {
            // element to be added;
            char toAdd = s[right];
            // increase the window;
            // this will make sure that the window is always [left, right)
            right++;

            // update data inside this window.
            if (need.count(toAdd)) {
                window[toAdd]++;
                // 这里用 equal是因为如果用 >=的话 会导致valid重复增加.
                if (window[toAdd] == need[toAdd]) {
                    valid++;
                }
            }

            // enough element added, need to shrink the window
            while (valid == targetSize) {
                // update the min string here
                // at this point the window is still qualified.
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                char c = s[left];
                left++;
                if (need.count(c)) {
                    // window里的某个char的数量是可能大于need中的数量的，所以当刚好等于的时，再移除一个元素会不符合要求.
                    if (window[c] == need[c]) {
                        valid--;
                    }
                    window[c]--;
                }
            }
            // ！！！在这里更新是错误的，因为前面并不是 if else的关系，在while外
            // 并不是说已经满足了搜索条件
            // int currentLen = right - (left - 1);
            // if (currentLen < len) {
            //     start = left - 1;
            //     len = right - start;
            // }
        }

        return len == std::numeric_limits<int>::max() ? "" : s.substr(start, len);
    }
};