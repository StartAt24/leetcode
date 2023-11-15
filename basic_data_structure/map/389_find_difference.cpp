#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    char findTheDifference(string s, string t) {
         int res = 0;
         for (char c : s) {
            res = res ^ c;
         }
         for (char c : t) {
            res = res ^ c;
         }
         return char(res);
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> map(26, 0);
        for (auto c: s) {
            map[c-'a']++;
        }
        for (auto c: t) {
            map[c-'a']--;
        }
        for (int i = 0; i < map.size(); i++)
        {
            if (map[i] != 0)
                return char(i+'a');
        }
    }
};