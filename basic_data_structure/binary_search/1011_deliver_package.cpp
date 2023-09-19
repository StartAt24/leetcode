#include "common.hpp"

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // 最小装载大小应该是 货物里的最大的那个
        // 最大装载大小是 题目的约束条件里的
        int left = *std::max_element(weights.begin(), weights.end()), right = std::accumulate(weights.begin(), weights.end(), 0) + 1;

        // 随着 cap变大 days是减少的，所以是一个单调递减的函数
        // 题目求的是符合条件的cap的最小值, 所以应该尽量往左边
        while (left < right) {
            int mid = left + (right - left) / 2;
            int d = daysNeed4Caps(weights, mid);
            if (d == days) {
                right = mid;
            } else if (d > days) {
                // 让d减少即增加重量
                left = mid + 1;
            } else if (d < days) {
                // 让d增大即减少重量
                right = mid;
            }
        }

        return left;
    }

private:
    int daysNeed4Caps(const vector<int>& weights, int cap) {
        int ret = 0;
        int total = 0;
        // 从左到右遍历，当重量满足的时候为一趟，如果重量超过了，则是下一趟。
        for (int i = 0; i < weights.size(); i++) {
            total += weights[i];
            if (total > cap) {
                ret++;
                total = 0;
                i--;
            }
        }
        if (total != 0)
            ret++;

        return ret;
    }
};