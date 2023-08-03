#include <vector>
using std::vector;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lastEmpty = 0;
        for (int i=0; i<nums.size(); i++) {
            if(nums[i] != val) {
                nums[lastEmpty] = nums[i];
                lastEmpty++;
            }
        }
        return lastEmpty;
    }
};