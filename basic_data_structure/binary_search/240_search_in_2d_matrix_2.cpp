#include "common.hpp"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int rows = matrix.size();

        int y = rows - 1;
        int x = 0;

        int bottom_left = matrix[rows-1][0];

        while(x <= cols-1 && y >= 0) {
            int val = matrix[y][x];
            if (val == target)
                return true;
            else if (val < target)
                x++;
            else if (val > target)
                y--;
        }

        return false;
    }
};