#include "common.hpp"

// 即每個内部的数组 按从小到大排序
// 每个数组的相同位置的元素按照从小到大排序
// 及从左上角到右下角是依次增大的
/*
[[1,   5,  9],
 [10, 11, 13]
 [12, 13, 15]
]
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 合并N个有序链表
        vector<int> listIdx(0, matrix.size());
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for(int i = 0; i < k; i++) {
            // loop all the list;
            int minVal = std::numeric_limit<int>::max();
            for (int idx = 0; idx < matrix.size(); idx++) {
                int val = matrix[idx][listIdx[idx]];
                if(val<minVal)
                    minVal = val;
            }

            for (int j = 0; j < matrix.size(); j++) {
                int val = matrix[j][listIdx[j]];
                if (val == minVal)
                    listIdx[j]++;
            }

            minHeap.push(minVal);
        }

        return minHeap.top();
    }
};