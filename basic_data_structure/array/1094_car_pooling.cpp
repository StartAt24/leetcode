#include "common.hpp"
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 注意看题目的contrains,来获取额外的信息。
        _diff.resize(1001);
        for (const auto& op: trips) {
            // 注意 乘客这个题目，乘客在终点站的时候 已经下车了。即其存在的周期是 [i, j-1];
            process(op[1], op[2]-1, op[0]);
        }

        auto res = result();

        for (const auto& val: res) {
            if (val > capacity)
                return false;
        }

        return true; 
    }
private:
    vector<int> result(){
        vector<int> res(_diff.size(), 0);
        res[0] = _diff[0];
        for (int i = 1; i < _diff.size(); i++) {
            res[i] = res[i-1] + _diff[i];
        }
        return res;
    }

    void process(int i, int j, int val) {
        _diff[i] += val;
        if (j+1 < _diff.size()) {
            _diff[j+1] -= val;
        }
    }

private:
    vector<int> _diff;
};