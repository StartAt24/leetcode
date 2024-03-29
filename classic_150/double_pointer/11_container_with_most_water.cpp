#include <vector>
using std::vector;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, res = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            area = (right - left) * min(height[left], height[right]);
            res = max(res, area);
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};