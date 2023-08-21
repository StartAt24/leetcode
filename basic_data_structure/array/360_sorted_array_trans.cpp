#include "common.hpp"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums, int a, int b, int c) {
        int l=0, r = nums.size()-1;
        int size = nums.size();
        vector<int> res(size);
        while(l<=r) {
            int left = f(nums[l], a, b, c);
            int right = f(nums[r], a, b, c);
            if (left > right) {
                res[--size] = left;
                left++;
            } else {
                res[--size] = right;
                right--;
            }
        }
        return res;
    }
private:
    int f(int x, int a, int b, int c){
        return x*x*a + b*x + c;
    }
};
