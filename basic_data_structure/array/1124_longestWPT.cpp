#include "common.hpp"
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // 如果大于8 则 记为1 小于8则记为0
        // 构建前缀和 数组
        int n = hours.size();
        const int limit_hour = 8;
        int sum = 0;
        int max_len = 0;
        unordered_map<int, int> ump;

        // 过一遍hash
        for (int i = 0; i < n; i++) {
            // 工作天数大于休息天数
            sum += hours[i] > limit_hour? 1: -1;
            // 说明从0到当前 >8 的天数 大于小于 8的天数
            if (sum > 0) {
                // i是index, i+1 才是实际的长度
                max_len = max(max_len, i+1);
            
            } else {
                // 如果当前小于0 则记下当前的总和值及其对应的位置i
                // 如果当前位置是负数的话，则去找 比他更小的一个负数，如果能找到就说明 从第一个位置以后(不包括第一个位置)到第二个位置为止（包含第二个位置）
                // 的值为正数
                if (ump.contains(sum-1)) {
                    max_len = max(max_len, i - ump[sum-1]);
                }
            }

            // 只存尽量靠前位置的值，这样可以尽量拿到最大长度
            if (!ump.contains(sum))
                ump[sum] = i;
        }

        return max_len;
    }
};