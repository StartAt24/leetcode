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

class NumArray2 {
public:
    NumArray2(vector<int>& nums) {
        // calc the accu value when initialize
        // 0 as the first index to calc easlier.
        _nums.resize(nums.size() + 1);
        _nums[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            _nums[i+1] = _nums[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return _nums[right+1] - _nums[left];
    }
private:
    std::vector<int> _nums;
};
