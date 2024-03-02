#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // wether s is a subsequence of t;
        int p1 = 0, p2 = 0;
        while (p1 < s.size() && p2 < t.size()) {
            if(s[p1] == t[p2]) {
                p1++;
                p2++;
            } else {
                p2++;
            }
        }

        if (p1 == s.size()) {
            return true;
        }

        return false;
    }
};