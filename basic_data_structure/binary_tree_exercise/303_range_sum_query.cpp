#include <vector>
using std::vector;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        _preSum.resize(n+1, 0);
        for (int i = 0; i < n; i++) {
            _preSum[i+1] = _preSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return _preSum[right+1] - _preSum[left];
    }
private:
    vector<int> _preSum;
};