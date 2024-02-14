#include <string>
#include <map>
using namespace std;

// limitation: 1<=num <=3999
class Solution {
public:
    string intToRoman(int num) {
        string ret;
        // 个位
        for (int i = 0; i < 13; i++) {
            while(num >= _values[i]) {
                num -= _values[i];
                ret += _reps[i];
            }
        }
        return ret;
    }

private:
    int _values[13] = {
        1000,
        900,
        500,
        400,
        100,
        90,
        50,
        40,
        10,
        9,
        5,
        4,
        1
    };

    string _reps[13] = {
        "M",
        "CM",
        "D",
        "CD",
        "C",
        "XC",
        "L",
        "XL",
        "X",
        "IX",
        "V",
        "IV",
        "I"
    };
};