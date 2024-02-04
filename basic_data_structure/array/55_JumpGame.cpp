#include <vector>
using std::vector;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump(nums, 0);
    }
private:
    // cong index i 开始走到最尾巴
    bool canJump(vector<int>& nums, int i) {
        if (i >= nums.size())
            return false;

        int cap = nums[i];
        int rest = nums.size() - 1 - i;
        if (cap >= rest)
            return true;
        
        for (int j = cap; j >= 1; j--) {
            if (canJump(nums, i+j))
                return true;
            
        }
        return false;
    }
};