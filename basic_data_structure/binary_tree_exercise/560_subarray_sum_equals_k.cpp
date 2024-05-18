#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> preSum(nums.size()+1, 0);
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            preSum[i+1] = preSum[i] + nums[i];
            int targetVal = preSum[i+1] - k;
            if (m.find(targetVal) != m.end()) {
                res+= m[targetVal];
            }
            m[preSum[i+1]]++;
        }
        return res;
    }
};