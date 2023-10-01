#include "common.hpp"

int numDistinct(string s, string t) {
    string txt = s;
    string pattern = t;

    const int L = pattern.length();
    // only handle ASCII string 
    const int R = 256;
    // preset RL for remove front operation
    const int RL = pow(R, L - 1);

    int windowHash = 0;
    long long patHash = 0;
    for (const auto& c: pattern) {
        patHash = patHash*R + c;
    }

    int left = 0, right = 0;
    while (right < txt.size()) {
        windowHash = R*windowHash + txt[right];
        right++;

        if (right - left == L){
            if (patHash == windowHash) {
                return left;
            }
        }

        windowHash = windowHash - txt[left]*RL;
        left++;
    }

    return -1;
}