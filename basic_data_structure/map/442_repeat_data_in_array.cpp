#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(auto n: nums) {
            if (nums[abs(n)-1] < 0) {
                res.push_back(n);
            } else {
                // mark it as exisit;
                nums[n-1] *= -1;
            }
        }
        return res;
    }
};