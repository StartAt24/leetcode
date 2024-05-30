#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        traverse(s, wordDict);
        return _res;
    }
private:
    void traverse(string s, const vector<string>& wordDict) {
        if (s.size() == 0) {
            _res = true;
            return;
        }
        
        for (auto word : wordDict) {
            if (s.starts_with(word)) {
                traverse(s.substr(word.length()-1), wordDict);
            }
        }
    }

    bool _res = false;
};