#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = s.size()-1;
        // we need to use those two pointer to loop from the center.
        // two possible cases the string is odd or even.
        string ret;
        for(auto i = 0; i < s.size(); i++) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i+1);
            ret = ret.size() < s1.size() ? s1:ret;
            ret = ret.size() < s2.size() ? s2:ret;
        }
        return ret;
    }
private:
    string palindrome(string s, int l, int r){
        while (l>=0 && r<s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        // a b c d e
        return s.substr(l+1, r-(l+1));
    }
};