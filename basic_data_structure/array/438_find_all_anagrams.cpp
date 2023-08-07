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
    }
};