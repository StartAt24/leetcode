#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> twoSumTarget(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size()-1;
    vector<vector<int>> res;
    while(left < right) {
        int sum = nums[left] + nums[right];
        int leftValue = nums[left];
        int rightValue = nums[right];
        if (sum < target) {
            // increase left, and skip same value;
            while(left < right && nums[left] == leftValue)
                left++;
        }
        else if (sum > target) {
            // decrease right and skip same value;
            while(left < right && nums[right] == rightValue)
                right--;
        }else {
            res.push_back({left, right});
            // skip same value to avoid repeated answers;
            while (left < right && nums[left] == leftValue) {
                left++;
            }
            while(left < right && nums[right] == rightValue)
                right--;
        }
    }
    return res;
}