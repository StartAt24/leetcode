#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ret;

        vector<string> rows;
        rows.resize(numRows);
        int i = 0;
        int flag = -1;

        for (auto c : s) {
            rows[i].push_back(c);
            if (i == 0 || i == numRows-1) {
                flag = -flag;
            }
            i+=flag;

        }
        for (auto str : rows ) {
            ret += str;
        }

        return ret;
    }
};