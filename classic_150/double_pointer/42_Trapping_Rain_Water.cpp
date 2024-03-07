#include <vector>
using std::vector;
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxLeft = 0, maxRight = 0;
        int ret = 0;
        while(left < right) {
            //注意！ 随着指针的移动 max的值 是不会减小的。
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);

            // left is a valid place
            if (maxLeft < maxRight) {
                ret += (maxLeft - height[left]);
                left++;
            } else {
                ret += (maxRight - height[right]);
                right--;
            }
        }
        return ret;
    }
};