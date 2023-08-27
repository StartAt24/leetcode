#include "common.hpp"
class NumArray {
public:
    NumArray(vector<int>& nums) {
        _nums = nums;
    }
    
    int sumRange(int left, int right) {
        int ret = 0;
        for (int i = left; i <= right; i++) {
            ret += _nums[i];
        }
        return ret;
    }
private:
    std::vector<int> _nums;
};
