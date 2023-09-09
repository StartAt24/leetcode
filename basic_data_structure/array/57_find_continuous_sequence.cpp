#include "common.hpp"

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ret;
        unordered_map<long long, int> pre_sum_map{{0,0}};
        long long pre_sum = 0;
        for (int i = 1; i < target; i++) {
            pre_sum += i;
            pre_sum_map[pre_sum] = i;
            // 查找和是否为 target或者 是否为 pre_sum[i] - pre_sum[j] = target;
            int target_val = pre_sum - target;
            if (pre_sum_map.contains(target_val)) {
                int j = pre_sum_map[target_val];
                vector<int> temp;
                for (int s = j+1; s <= i; s++) {
                    temp.push_back(s);
                }
                ret.push_back(temp);
            }
        }
        return ret;
    }
};