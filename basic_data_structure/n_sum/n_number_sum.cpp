#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> TwoSum(vector<int> nums, int target, int leftIdx) {
    sort(nums.begin(), nums.end());
    int left = leftIdx, right = nums.size() - 1;
    vector<vector<int>> res;
    while (left < right) {
        int leftVal = nums[left];
        int rightVal = nums[right];
        int sum = leftVal + rightVal;
        if (sum < target) {
            while(left < right && nums[left] == leftVal)
                left++;
        } else if (sum > target) {
            while (left < right && nums[right] == rightVal)
                right--;
        } else {
            nums.push_back({nums[left], nums[right]});
            while(left < right && nums[left] == leftVal)
                left++;
            while (left < right && nums[right] == rightVal)
                right--;
        }
    }
    return res;
}

vector<vector<int>> NSum(vector<int> nums, int target, int leftIdx, int count) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    if (count == 2) {
        return TwoSum(nums, target, leftIdx);
    }
    
    int n = nums.size();

    for (int i = leftIdx; i < n; i++) {
        // return 当前的 num + 剩余count的N Sum
        int tempTarget = target - nums[leftIdx];
        auto rest = NSum(nums, tempTarget, leftIdx + 1, count - 1);
        for (auto & v : rest) {
            v.push_back(nums[leftIdx]);
            res.push_back(v);
        }
        while (i < n-1 && nums[i] == nums[i+1]) i++;
    }

    return res;
}