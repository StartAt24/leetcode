#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'I' && i+1 < s.size()) {
                char next = s[i+1];
                if (next == 'V') {
                    ret += 4;
                    i++;
                    continue;
                }
                if (next == 'X') {
                    ret += 9;
                    i++;
                    continue;
                }
            }

            if (c == 'X' && i+1 < s.size()) {
                char next = s[i+1];
                if (next == 'L') {
                    ret += 40;
                    i++;
                    continue;
                }
                if (next == 'C') {
                    ret += 90;
                    i++;
                    continue;
                }
            }

            if (c == 'C' && i+1 < s.size()) {
                char next = s[i+1];
                if (next == 'D') {
                    ret += 400;
                    i++;
                    continue;
                }
                if (next == 'M') {
                    ret += 900;
                    i++;
                    continue;
                }
            }
            ret += _char2Int[c];
        }

        return ret;
    }
private:
    unordered_map<char, int> _char2Int {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
};