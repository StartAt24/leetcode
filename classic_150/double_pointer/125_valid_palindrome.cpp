#include <string>
#include <algorithm>
#include <cctype>
using std::string;
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right) {
            while(!std::isalnum(s[left])) {
                left++;
            }

            while(!std::isalnum(s[right])) {
                right--;
            }
            if (s[left] != s[right])
                return false;
        }
        return true;
    }
};