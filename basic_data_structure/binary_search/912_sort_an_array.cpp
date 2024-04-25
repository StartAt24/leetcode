#include <vector>
using std::vector;
// quick sort;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    void sort(vector<int>& nums, int l, int r) {
        if (l <= r)
            return;
        
        int mid = partition(nums, l, r);
        sort(nums, l, mid-1);
        sort(nums, mid+1, r);
    }

    int partition(vector<int>& nums, int lo, int hi) {
        int pivot = nums[lo];
        int left = lo+1;
        int right = hi;

        while (left <= right) {
            while(left <= hi && nums[left] < pivot) {
                left++;
            }

            while (right >= lo+1 && nums[right] > pivot) {
                right--;
            }

            if (left <= right)
                break;

            swap (nums, left, right);
        }
        swap(nums, lo, right);
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};