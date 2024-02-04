#include <vector>
using std::vector;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump(nums, 0);
    }

private:
    // cong index i 开始走到最尾巴
    bool canJump(vector<int>& nums, int i) {
        if (i >= nums.size())
            return false;

        int cap = nums[i];
        int rest = nums.size() - 1 - i;
        if (cap >= rest)
            return true;
        
        for (int j = cap; j >= 1; j--) {
            if (canJump(nums, i+j))
                return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int fareast = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            fareast = std::max(fareast, i + nums[i]);
            // 表明 当前节点到不了
            // 如果 fareast < i 则说明到不了当前节点了
            // 如果 fareast = i 则说明 i这个节点的 value是0, 走了等于没走
            if (fareast <= i) {
                return false;
            }
        }
        // 这里的fareast是 index
        return fareast >= n-1;
    }
};