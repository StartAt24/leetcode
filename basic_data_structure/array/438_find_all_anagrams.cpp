#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        #if 0
        if (p.size() == 0 || s.size() == 0)
            return vector<int>{};

        // remember that the needed number might not only be 1!!!
        map<char, int> need;
        map<char, int> window;

        // in window it's [left, right)
        int left = 0, right = 0;
        int valid = 0;

        for (auto c : p) {
            need[c]++;
        }

        while(right < s.size()){
            char c = p[right];
            right++;

            // update window;
            if (need[c]) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            

        }
        #endif
#if MYSolution
        if (s.size() == 0 || p.size() == 0 || p.size() > s.size())
            return vector<int>{};

        map<char, int> need;
        for (auto c: p) {
            need[c]++;
        }

        map<char, int> window;

        auto satify = [&] () {
            for(const auto [k,v] : need){
                if (window[k] != v)
                    return false;
            }
            return true;
        };
        int left = 0, right = p.size();

        for (int i = 0; i < p.size(); i++) {
            window[s[i]]++;
        }

        vector<int> ret;
        while(right <= s.size()) {
            if(satify())
                ret.push_back(left);

            char a = s[right];
            right++;
            window[a]++;

            char d = s[left];
            window[d]--;
            left++;
        }
        return ret;
    #endif // MySoltution
        vector<int> ret;
        map<char, int> need, window;
        int left = 0, right = 0, valid = 0;

        for (auto c: p) {
            need[c]++;
        }

        while (right < s.size()) {
            char c = s[right];
            right++;
            // the window is [left, right), execlu

            // update window
            if (need.count(c)) {
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }

            // if the window > p.size() need to shrink.
            // here we need equal, since right is execlude.
            // 0, 1, 2, 3, 4 


            while(right-left >= p.size()) {
                // now we meet the condition that the size of string in window  
                if (valid == need.size()) {
                    ret.push_back(left);
                }

                char d = s[left];
                left++;
                if (need.count(d)) {
                    // at this point the valid status will be break.
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return ret;
    }
};