#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        _extraSpace.resize(nums.size());
        sort(nums, 0, nums.size()-1);
        return nums;
    }

private:
    void sort(vector<int>& nums, int lo, int hi) {
        if(lo == hi)
            return;

        int mid = lo + (hi-lo)/2;
        sort(nums, lo, mid);
        sort(nums, mid+1, hi);

        merge(nums, lo, mid, hi);
        return;
    }

    void merge(vector<int>& nums, int lo, int mid, int hi) {
        int p1 = lo;
        int p2 = mid + 1;
        for(int i = lo; i <=hi; i++) {
            // 左边以及取完了，取右边
            if (p1 > mid) {
                _extraSpace[i] = nums[p2++];
            } else if (p2 > hi) {
                _extraSpace[i] = nums[p1++];
            } else if (nums[p1] < nums[p2]) {
                _extraSpace[i] = nums[p1++];
            } else {
                _extraSpace[i] = nums[p2++];
            }
        }
        for (int i = lo; i <=hi; i++) {
            nums[i] = _extraSpace[i];
        }
    }

    vector<int> _extraSpace;
};