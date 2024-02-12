#include <vector>
using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int l_max = 0, r_max = 0;
        int res = 0;
        while(left < right) {
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);
            if (l_max < r_max) {
                res += l_max - height[left];
                left++;
            } else {
                res += r_max - height[right];
                right--;
            }
        }
        return res;
    }
};