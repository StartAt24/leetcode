#include "common.hpp"
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // reserve size
        vector<vector<int>> res(n);
        for (auto& line: res ){
            line.resize(n);
        }
        int top_limit = 0, right_limit= n-1, bottom_limit=n-1, left_limit=0;
        int num = 1;
        while(num <= n*n){
            // top
            if (top_limit <= bottom_limit) {
                for (int x = left_limit; x <= right_limit; x++){
                    res[top_limit][x] = num++;
                }
                top_limit++;
            }

            // right
            if (left_limit <= right_limit) {
                for (int y = top_limit; y<= bottom_limit; y++){
                    res[y][right_limit] = num++;
                }
                right_limit--;
            }

            // bottom
            if (top_limit <= bottom_limit) {
                for (int x = right_limit; x>=left_limit; x--) {
                    res[bottom_limit][x] = num++;
                }
                bottom_limit--;
            }

            // left
            if (left_limit <= right_limit) {
                for (int y = bottom_limit; y>= top_limit; y--){
                    res[y][left_limit] = num++;
                }
                left_limit++;
            }
        }
        return res;
    }
};