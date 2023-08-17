#include "common.hpp"
#include <limits>

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
        int listCount = matrix.size();
        vector<int> listIdx(listCount);
        // max heap
        std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
        for(int i = 0; i < k; i++) {
            // loop all the list;
            int minVal = std::numeric_limits<int>::max();

            for (int idx = 0; idx < listCount; idx++) {
                const auto& currentList = matrix[idx];
                int pointer = listIdx[idx];
                if (pointer >= matrix.at(0).size())
                    continue;
                int val = currentList[pointer];
                if( val < minVal)
                    minVal = val;
            }

            for (int j = 0; j < listCount; j++) {
                if(listIdx[j] >= matrix[0].size())
                    continue;
                int val = matrix[j][listIdx[j]];
                if (val == minVal) {
                    listIdx[j]++;
                    break;
                }
            }

            maxHeap.push(minVal);
        }

        return maxHeap.top();
    }
};

int main() {
    vector<vector<int>> matrix(2);
    vector<int> a;
    a.push_back(1);
    a.push_back(2);

    vector<int> b;
    b.push_back(1);
    b.push_back(3);
    
    vector<int> c;
    c.push_back(12);
    c.push_back(13);
    c.push_back(15);

    matrix[0] = a;
    matrix[1] = b;
    // matrix[2] = c;

    int k = 4;
    Solution s;
    int val = s.kthSmallest(matrix, k);
    return 0;
}