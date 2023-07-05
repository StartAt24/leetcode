#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int slow = 0;


        for (int i=0; i<nums.size(); i++) {
            if (nums[slow] != nums[i]) {
                // different num add to end;
                nums[++slow] = nums[i];
            }
        }
        // return the size of this array.
        return slow+1;
    }
};