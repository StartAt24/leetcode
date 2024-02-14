#include <string>
#include <map>
using namespace std;

// limitation: 1<=num <=3999
class Solution {
public:
    string intToRoman(int num) {
        string ret;
        // 个位
        int n = num%10;
        if (n>=1 && n<4) {
            while(n--) {
                
            }
        }

        
    }

private:
    unordered_map<int, string> _int2Char {
        {1, 'I'},
        {4, 'IV'},
        {5, 'V'},
        {9, 'IX'},
        {10, 'X'},
        {40, 'XL'},
        {50, 'L'},
        {90, 'XC'},
        {100, 'C'},
        {400, 'CD'},
        {500, 'D'},
        {900, 'CM'},
        {1000, 'M'}
    };
};