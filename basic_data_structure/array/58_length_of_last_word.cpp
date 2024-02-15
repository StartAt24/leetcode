#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;

        // end with ' '
        // strip ' '
        while(!s.empty() && s.back() == ' ') {
            s.pop_back();
        }

        int i = s.size() - 1;

        while(i>=0) {
            if (s[i] == ' ') {
                break;
            }
            i--;
        }
        // " hello"
        // size = 6
        // i = 0;
        return s.size() - 1 - i;
    }
};