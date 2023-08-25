#include "common.hpp"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int w = matrix[0].size();
        int h = matrix.size();
        int count = w * h;
        int left_limit = 0, top_limit=0, right_limit=w-1, bottom_limit = h-1;

        while (res.size() < count) {
            // print top;
            if (top_limit <= bottom_limit) {
                for (int x = left_limit; x <= right_limit; x++) {
                    res.push_back(matrix[top_limit][x]);
                }
                top_limit++;
            }
            // print right;
            if (left_limit <= right_limit) {
                for (int y = top_limit; y<= bottom_limit; y++){
                    res.push_back(matrix[y][right_limit]);
                }
                right_limit--;
            }
            // print bottom;
            if (top_limit <= bottom_limit) {
                for (int x = right_limit; x>= left_limit; x--) {
                    res.push_back(matrix[bottom_limit][x]);
                }
                bottom_limit--;
            }

            // print left;
            if (left_limit <= right_limit) {
                for (int y = bottom_limit; y>= top_limit; y--){
                    res.push_back(matrix[y][left_limit]);
                }
                left_limit++;
            }
        }
        return res;
    }
};