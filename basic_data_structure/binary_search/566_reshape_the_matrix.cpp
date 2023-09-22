#include "common.hpp"

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m*n != r*c)
            return mat;

        vector<vector<int>> ret;
        for (int y = 0; y < r; y++) {
            vector<int> row(c, 0);
            for (int x = 0; x < c; x++) {
                row[x] = getSize(x, y, c, mat);
            }
            ret.push_back(row);
        }
        return ret;
    }
private:
    int getSize(int x, int y, int w,const vector<vector<int>>& mat) {
        int abs_idx = w*y+x;
        int width = mat[0].size();
        return mat[abs_idx/width][abs_idx%width];
    }
};