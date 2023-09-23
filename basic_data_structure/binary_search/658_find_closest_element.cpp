#include "common.hpp"

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // binary search the indx;
        int idx = findMostLeftIndex(arr, x);
        std::list<int> s;
        int left = idx-1, right = idx;
        // 两端都是开的区间(left, right)
        while(right-left-1 < k) {
            if (left == -1) {
                s.push_back(arr[right]);
                right++;
            } else if (right == arr.size()){
                s.push_front(arr[left]);
                left--;
            } else if (abs(arr[right]-x) < abs(arr[left] - x)){
                s.push_back(arr[right]);
                right++;
            } else {
                s.push_front(arr[left]);
                left--;
            }
        }
        vector<int> ans;
        for(const auto & e : s) {
            ans.push_back(e);
        }
        return ans; 
    }

private:
    int findMostLeftIndex(vector<int>& arr, int target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left)/2;
            int val = arr[mid];
            if (val == target) {
                right = mid;
            } else if (val < target) {
                left = mid + 1;
            } else if (val > target) {
                right = mid;
            }
        }
        return left == arr.size() ? left - 1: left;
    }
};