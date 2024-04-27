#include <vector>
#include <queue>
using std::vector;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int ,vector<int>, std::less<int>> maxHeap;
        for(auto n : nums) {
            maxHeap.insert(n);
        }

        while (k--) {
            maxHeap.pop();
        }

        return maxHeap.top() 
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        _targetPisition = nums.size() - k;
        sort(nums, 0, nums.size()-1);
        return _res;
    }

private:
    void sort(vector<int>& nums, int lo, int hi) {
        if (lo>=hi)
            return;
        // 将选择的pivot排序到正确的位置
        int p = partition(nums, lo, hi);
        if (p < _targetPisition) {
            sort(nums, p+1, hi);
        } else {
            sort(nums, lo, p-1);
        } else {
            _res =  nums[p];
            return;
        }
    }

    int partition(vector<int>& nums, int lo, int hi) {
        int pivot = nums[lo];
        int left = lo+1;
        int right = hi;
        while (1) {
            while (left <= right && nums[left] <= pivot) {
                left++;
            }
            while (left <= right && nums[right] > pivot) {
                right--;
            }

            if (left >= right)
                break;
            swap(nums[left], nums[right]);
        }
        swap(nums[lo], mums[right]);
        return right;
    }
    
    int _targetPisition = 0;
    int _res = 0;
};