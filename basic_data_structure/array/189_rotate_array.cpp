#include <vector>
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        
        // 1,2,3,4,5
        // 5,4,3,2,1
        // 4,5,1,2,3

        // 1,2,3
        // 3,2,1
        // 3,1,2
        revert(0, nums.size()-1, nums);
        revert(0, k-1, nums);
        revert(k, nums.size()-1, nums);
    }
private:
    void revert(int l, int r, vector<int>& nums) {
        while(l < r) {
            swap(l, r, nums);
            l++;
            r--;
        }
    }

    void swap(int i, int j, vector<int>& nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};