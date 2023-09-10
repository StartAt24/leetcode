#include "common.hpp"

class Solution {
public:
    vector<int> getModifiedArray(int len, vector<vector<int>> updates) {
        // vector 默认resize值应该就是0.
        _diff.resize(len);
        for (const auto& op : updates) {
            increasement(op[0], op[1], op[2]);
        }
        return result();
    }

private:
    void increasement(int start, int end, int val) {
        _diff[start] += val;
        if (end < _diff.size() - 1) {
            _diff[end] -= val;
        }
    }
    vector<int> result() {
        vector<int> ret(_diff.size(), 0);
        for(int i = 1; i < _diff.size(); i++) {
            ret[i] = ret[i-1] + _diff[i];
        }
        return ret;
    }
    // diff[i] = array[i] - array[i-1];
    // array[i] = diff[i] + array[i-1];
    vector<int> _diff;
};