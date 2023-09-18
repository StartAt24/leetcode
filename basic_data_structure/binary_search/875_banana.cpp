#include "common.hpp"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // left 及 right应该是跟 x是对应的，
        // 所以是吃香蕉速度的最小值和最大值。最小值应该是1.
        // 最大值可以根据题目来 (根据题目预设的可能会越界)
        // ，或者遍历piles看看最大值。
        int max = *std::max_element(piles.begin(), piles.end());
        int left = 0, right = max + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int val = f(mid, piles);
            if ( val <= h)
            {
                // 求的是x的最小值，及求的是左边界。
                // 但是因为 函数f是单调递减的，所以要看好怎么left, right的调整
                right = mid;
            } else if ( val > h) {
                // 需要 f(x) 返回值小一点，单调递减情况下， 向右移动
                left = mid + 1;
            }
        }
        // 因为求的是一个值，而不是是否等于。所以可以直接return left;
        return left;
    }
private:
    // 寻找 x 以及 f(x)
    long f(int x, const vector<int>& piles) {
        long hours = 0;
        if (x == 0) return INT_MAX;
        for (const auto& pile: piles) {
            hours += pile / x;
            if (pile % x > 0)
                hours++;
        }
        return hours;
    }
};