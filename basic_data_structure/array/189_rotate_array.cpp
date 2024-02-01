#include <vector>
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // 1,2,3,4,5
        // 5,4,3,2,1
        // 4,5,1,2,3

        // 1,2,3
        // 3,2,1
        // 3,1,2
        for (int i = 0; i < n; i++) {
            int newIdx = (i+k)%n;
            swap(i, newIdx, nums);

        }
    }
private:
    void revert()
    
};