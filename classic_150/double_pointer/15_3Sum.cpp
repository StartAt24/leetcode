#include <map>
#include <vector>
using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto n : nums) {
            m[n]++;
        }
        vector<int> noDup;
        for (auto [k,v] : m) {
            noDup.push_back(k);
        }

        vector<vector<int>> res;
        for (int i = 0; i < noDup.size(); i++) {
            for (int j = i; j < noDup.size(); j++) {
                int target = 0 - noDup[i] - noDup[j];
                if (m.contains(target) && target != noDup[i] && target != noDup[j]) {
                    vector<int> temp{noDup[i], noDup[j], target};
                    res.push_back(temp);
                }
            }
        }

        return res;
    }
};