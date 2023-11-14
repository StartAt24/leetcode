#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target = 0;
        int count = 0;

        // 1,3,1,0
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                target = nums[i];
                count = 1;
            } 
            else if (nums[i] == target) {
                count++;
            } else {
                count--;
            }
        }
        return target;
    }
};