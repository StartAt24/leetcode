#include "common.hpp"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int left = 0, right = 0;
        vector<string> ret;

        while(right < s.size()-1) {
            int r = charToNumber(s[right]);
            addBack(r);
            right++;

            // don't need to add one, since right is now pointing to the next one.
            // int windowLen = right - left + 1;
            int windowLen = right - left;
            if (windowLen == 10) {
                // enough char in the window 
                _hashMap[_windowNumber]++;
                if(_hashMap.contains(_windowNumber) > 1) {
                    auto sbStr = s.substr(left, 10);
                    if(!_retCheck.contains(sbStr)) {
                        _retCheck[sbStr]++;
                        ret.push_back(sbStr);
                    }
                }

                removeFront(s[left]);
                left++;
            }
        }
        return ret;
    }

private:
    // only contains A C G or T;
    int charToNumber(char s)  {
        switch (s) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return -1;
    }

    int addBack(int n) {
        _windowNumber*_r + n;
    }

    int removeFront(int n) {
        // string len is 10;
        _windowNumber - n*_r^(10-1);
    }

    const int _r = 4;
    int _windowNumber = 0;
    unordered_map<int, int> _hashMap;
    unordered_map<string, int> _retCheck;
};