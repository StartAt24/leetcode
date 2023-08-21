#include "common.hpp"
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // two pointer, one from begin another from the end?
        // and sort the nums from the last one;
        int l = 0, r = nums.size()-1;
        std::vector<int> res;
        int size = nums.size();
        res.resize(size);

        while (l<=r){
            int left = nums[l]*nums[l];
            int right = nums[r]*nums[r];

            int max = std::max(left, right);
            if (max == left) {
                l++;
            } else {
                r--;
            }
            res[--size] = max;
        }
        return res;
    }
};
