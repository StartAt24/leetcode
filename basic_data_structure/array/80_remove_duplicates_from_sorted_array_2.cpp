#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int slow = 1;
        int preValue = nums[0];
        bool bAddTwice = false;

        for (int i = 1; i <nums.size(); i++) {
            if (nums[i] == preValue && !bAddTwice) {
                nums[slow++] = preValue;
                bAddTwice = true;
            } else if (nums[i] != preValue){
                nums[slow++] = nums[i];
                preValue = nums[i];
                bAddTwice = false;
            }
        }
        return slow;
    }

    int removeDuplicates2(vector<int>& nums) {
        int n = nums.size();
        if (n <=2 )
            return n;

        int slow = 2, fast = 2;
        while (fast < n) {
            // 因为允许两个重复。所以，我们要跟倒数第2个数比较，但是因为slow指向的是下次插入的位置，所以这里是-2；
            if (nums[slow-2] != nums[fast]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }
};