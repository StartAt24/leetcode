#include <vector>
using std::vector;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0, farthest = 0;
        int jumps = 0;
        for (int i = 0; i < n; i++) {
            //从当前节点最远能跳到的节点.
            farthest = std::max(farthest, nums[i]+i);
            // 如果当前节点是上一次最远能跳到的节点
            // 则更新end, 并且将当前作为一次成功的跳跃
            if (i == end) {
                end = farthest;
                jumps++;
            }
        }
        return jumps;
    }
};