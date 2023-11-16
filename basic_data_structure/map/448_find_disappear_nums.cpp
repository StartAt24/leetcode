#include <vector>
using std::vector;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (auto n : nums) {
            if (nums[abs(n) - 1] > 0)
                nums[abs(n)-1] *= -1;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]>0)
                res.push_back(i+1);
        }
        return res;
    }
};