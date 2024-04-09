#include <vector>
using std::vector;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        _temp.resize(size);
        _res.resize(size);
        vector<Pair> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = Pair(nums[i], i);
        }
        sort(arr, 0, size-1);
        return _res;
    }
private:
    struct Pair {
        Pair(int val, int id) {
            this->val = val;
            this->id = id;
        }
        Pair() {
            val = 0;
            id = 0;
        }
        Pair (const Pair& other) {
            val = other.val;
            id = other.id;
        }

        int val;
        int id;
    };

    void sort(vector<Pair>& arr, int lo, int hi) {
        if (lo == hi)
            return;
        
        int mid = lo + (hi-lo)/2;
        sort(arr, lo, mid);
        sort(arr, mid+1, hi);
        merge(arr, lo, mid, hi);
    }

    void merge(vector<Pair>& arr, int lo, int mid, int hi) {
        // backup first;
        for(int i = lo; i<=hi; i++) {
            _temp[i] = arr[i];
        }

        int l = lo, r = mid+1;
        for (int i = lo; i <= hi; i++) {
            // 题目要求的是比当前元素小的元素
            if (l == mid+1) {
                arr[i] = _temp[r++];
            } else if (r == hi+1) {
                arr[i] = _temp[l++];
                // 这个时候右边的数组已经遍历完了，只剩下左边的，且左边后续的都是比当前的大的,所以
                _res[arr[i].id] += r - (mid+1);
            } else if (_temp[l].val <= _temp[r].val) {
                // 当前左侧元素比右侧元素小
                arr[i] = _temp[l++];
                // 这个时候 左侧剩余的元素都比当前元素大，那么只有右侧的元素小于当前元素
                _res[arr[i].id] += r - (mid+1);
            } else {
                arr[i]  = _temp[r++];
            }
        }
    }


    // extra space
    vector<Pair> _temp;
    vector<int> _res;
};