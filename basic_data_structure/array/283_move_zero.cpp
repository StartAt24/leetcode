#include <vector>
using std::vector;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast =0;
        int size = nums.size();
        while (fast < size) {
            // if it is zero, mark this position as avaiable
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow ++;
            }
            
            fast++;
        }
        while(slow < size) {
            nums[slow] = 0;
            slow++;
        }
    }
};