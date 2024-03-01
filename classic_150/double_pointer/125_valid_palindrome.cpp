#include <string>
#include <algorithm>
#include <cctype>
using std::string;
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right) {
            while(left < s.size() && !std::isalnum(s[left])) {
                left++;
            }

            while(right>=0 && !std::isalnum(s[right])) {
                right--;
            }

            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) 
                    return false;
                left++;
                right--;
            }
        }
        return true;
    }
};