#include <vector>
using std::vector;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        _temp.resize(nums.size());
        sort(nums, 0, nums.size()-1);
        return _res;
    }
private:
    void sort(vector<int>& nums, int lo, int hi) {
        // don't need to sort for a single element;
        if (lo == hi)
            return;
        
        int mid = lo + (hi - lo) /2;
        sort(nums, lo, mid);
        sort(nums, mid+1, hi);

        merge(nums, lo, mid, hi);
    }

    void merge(vector<int>& nums, int lo, int mid, int hi) {
        // Need to have a copy before sort;
        // allocate the space one time at the initialization.
        for (int i = lo; i <= hi; i++) {
            _temp[i] = nums[i];
        }

        // 维护一个左闭右开的区间，这个好处是起始的时候 [mid+1, mid+1) 是一个空区间
        int end = mid + 1;
        // 根据题目的要求去 检查符合要求的值
        for (int i = lo; i<= mid; i++) {
            // 后面一个数字来的时候 end不需要重置，因为这个end当前的状态对于 目前的数字来说都是合规的
            while (end <= hi && (long)nums[i] > (long)nums[end] *2) {
                end++;
            }
            _res += (end - (mid + 1));
        }


        int leftPart = lo, rightPart = mid+1;
        for (int i = lo; i <= hi; i++) {
            // leftPart finished, only loop on right part
            if (leftPart == mid+1) {
                nums[i] = _temp[rightPart++];
            // rightpart finished, only loop on right part
            } else if (rightPart == hi+1) {
                nums[i] = _temp[leftPart++];
            } else if (_temp[leftPart] > _temp[rightPart]) {
                nums[i] = _temp[rightPart++];
            } else {
                nums[i] = _temp[leftPart++];
            }
        }
    }

    int _res = {0};
    vector<int> _temp;
};