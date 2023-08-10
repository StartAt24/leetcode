#include <vector>
using namespace std;
int binary_search(vector<int> nums, int target) {
    int left = 0, right = nums.size();
    while(left <= right) {
        int mid = (left + right)/2;
        if (mid == target)
            return mid;
        else if (mid < target) {
            left = mid + 1;
        } else if (mid > target) {
            right = mid - 1;
        }
    }
    return -1;
}