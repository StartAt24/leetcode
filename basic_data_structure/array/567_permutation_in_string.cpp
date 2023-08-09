#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> need, window;
        int valid = 0;
        int left = 0, right = 0;

        for(auto c: s1)
            need[c]++;


        while(right < s2.size()) {
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c])
                    valid++;
            }

            while(right - left >= s1.size()) {
                // check here;
                if (valid == need.size()) {
                    return true;
                }

                char d = s2[left];
                left++;
                if (need.count(d)) {
                    if (need[d] == window[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};