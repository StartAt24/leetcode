#include "common.hpp"
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        _diff.resize(n);
        for (const auto& op: bookings) {
            operate(op[0] - 1, op[1] - 1, op[2]);
        }
        return result();
    }
private:
    vector<int> result() {
        vector<int> ans(_diff.size(), 0);
        ans[0] = _diff[0];
        for (int i = 1; i < _diff.size(); i++) {
            ans[i] = ans[i-1] + _diff[i];
        }
        return ans;
    }
    
    void operate(int i, int j, int val) {
        _diff[i] += val;
        if (j < _diff.size() - 1) {
            _diff[j+1] -= val;
        }
    }

    vector<int> _diff;
};