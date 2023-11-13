#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(26, 0);
        for (auto c : s) {
            int idx = c - 'a';
            vec[idx]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if(vec[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};