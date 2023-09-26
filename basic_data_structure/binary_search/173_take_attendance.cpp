#include "common.hpp"

class Solution {
public:
    int takeAttendance(vector<int>& record) {
        int left = 0, right = record.size()-1;
        while (left  <= right) {
            int mid = left + (right-left)/2;
            // 数字的值大于他的indx,说明不对应，否则应该是对应的
            // 数组内容的值本来应该就等于他的index;
            if (record[mid] > mid) {
                // 元素对应不上，说明左侧缺少数字
                right = mid - 1;
            } else {
                // mid和 record[mid] 能对应上，则右侧缺少数字
                left = mid + 1;
            }
        }
        // 0,1,2,4
        return left;
    }
};