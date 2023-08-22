#include "common.hpp"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums, int a, int b, int c) {
        int l=0, r = nums.size()-1;
        int size = nums.size();
        vector<int> res(size);
        // 这是一个一元二次方程，所以要考虑开口的方向。
        // 开口方向向上则 两侧是向下递减的，则从 0 index开始填充
        // 开口方向向下，则两侧是递增的，从 end index开始填充
        int p = 0;
        if(a>=0) {
            p = 0;
        } else {
            p = nums.size() - 1;
        }

        while(l<=r) {
            int left = f(nums[l], a, b, c);
            int right = f(nums[r], a, b, c);
            if (left > right) {
                if (a>=0) {
                    res[p++] = right;
                } else {
                    res[p--] = left;
                }
                left++;
            } else {
                if (a>=0) {
                    res[p++] = left;
                } else {
                    res[p--] = right;
                }
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
