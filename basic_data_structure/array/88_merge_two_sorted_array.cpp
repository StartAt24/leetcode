#include "common.hpp"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1, p2 = n-1;
        // 从后往前排序可以避免覆盖原始元素的问题
        // 需要存放元素的指针
        int p_idx = nums1.size()-1;
        while (p1 >= 0 && p2 >= 0) {
            int maxVal = std::max(nums1[p1], nums2[p2]);
            if (maxVal == nums1[p1]) {
                p1--;
            } else {
                p2--;
            }
            nums1[p_idx] = maxVal;
            p_idx--;
        }
        // 只需要考虑nums2是否剩余元素，因为我们所有的元素都存在nums1里。即使nums1有元素的话 也无需操作
        while (p2 >= 0) {
            nums1[p_idx] = nums2[p2];
            p_idx--;
            p2--;
        }
    }
};