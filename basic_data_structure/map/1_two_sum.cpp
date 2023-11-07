#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            int leftValue = target - nums[i];
            if (_hashMap.find(leftValue) != _hashMap.end()) {
                return vector<int>{_hashMap[leftValue], i};
            }
            _hashMap[nums[i]] = i;
        }
        return {0, 0};
    }
private:
    unordered_map<int, int> _hashMap;
};