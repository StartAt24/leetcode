#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> _vec(26, 0);
        for(auto c : s) {
            _vec[c - 'a'] += 1;
        }

        for (auto c : t) {
            _vec[c - 'a'] -= 1;
        }

        for (auto i : _vec) {
            if (i != 0)
                return false;
        }
        return true;
    }

};