#include "common.hpp"
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = nums.size();
        vector<int> sum_vec(count + 1, 0);
        // 将 0 变成 -1 这样加起来和即为 0; 可以避免寻找最大值
        for (int i = 0; i < count; i++) {
            sum_vec[i+1] = sum_vec[i] + (nums[i] == 0 ? -1 : 1);
        }

        std::unordered_map<int, int> sum_map;
        int res = 0;

        for (int i = 0; i < sum_vec.size(); i++) {
            // 如果前缀和还没有对应的索引 则说明这个前缀和第一次出现，记录下来
            if(!sum_map.contains(sum_vec[i])) {
                sum_map[sum_vec[i]] = i;
            } else {
                // 如果当前位置的前缀和和 之前的某个一致，说明 从刚刚的坐标开始 到现在的坐标 中间的元素加起来为0
                int pre_idx = sum_map[sum_vec[i]];
                res = max(res, i - pre_idx);
            }
        }
        return res;
    }
};