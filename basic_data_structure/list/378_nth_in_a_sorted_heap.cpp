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

class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // priority queue;
        // minheap;
        std::priority_queue<Point, std::vector<Point>, std::greater<Point>> minHeap;
        // insert first element to
        for (int i = 0; i < matrix.size(); i++) {
            minHeap.push(Point(matrix[i][0], i, 0));
        }

        // pop K-1s element and the Kth one is the target one.
        for (int i = 0; i < k-1; i++) {
            auto current = minHeap.top();
            minHeap.pop();
            if(current.y != matrix.size() - 1) {
                minHeap.push({matrix[current.x][current.y+1], current.x, current.y+1});
            }
        }
        return minHeap.top().val;
    }
private:
    // this struct represent a Point in the matrix
    struct Point{
        int val, x, y;
        Point(int val, int x, int y):val(val), x(x), y(y) {}
        bool operator> (const Point& other) const {return this->val > other.val;};
    };

};

class Solution3{

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