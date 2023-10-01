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
 
                if(_hashMap.contains(_windowNumber)) {
                    auto sbStr = s.substr(left, 10);
                    if(!_retCheck.contains(sbStr)) {
                        _retCheck[sbStr]++;
                        ret.push_back(sbStr);
                    }
                } else {
                    _hashMap[_windowNumber]++;
                }

                int l = charToNumber(s[left]);
                removeFront(l);
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

    void addBack(int n) {
        _windowNumber = _windowNumber*_r + n;
    }

    void removeFront(int n) {
        // string len is 10;
        _windowNumber = _windowNumber - n*pow(_r, 9);
    }

    const int _r = 4;
    int _windowNumber = 0;
    unordered_map<int, int> _hashMap;
    unordered_map<string, int> _retCheck;
};