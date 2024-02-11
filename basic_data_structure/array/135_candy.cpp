#include <vector>
using std::vector;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> cadies;
        int total = 0;
        for (int i = 0; i < ratings.size(); i++) {
            total += require(ratings, i);
        }
        return total;
    }
private:
    int require(vector<int>& ratings, int idx)
    {
        int r = 1;
        if (idx-1 >0 && ratings[idx-1]<ratings[idx]) {
            r = max(r, require(ratings, idx-1)+1);
        }
        if (idx+1 < ratings.size() && ratings[idx+1] < ratings[idx]) {
            r = max(r, require(ratings, idx+1) +1);
        }
        return r;
    }
};