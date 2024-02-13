#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

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