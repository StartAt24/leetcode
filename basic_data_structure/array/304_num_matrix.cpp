#include "common.hpp"
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // calc the acclu sum.
        _sum_mat.resize(rows+1);
        for (auto& lines : _sum_mat){
            lines.resize(cols+1);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 总和等于 _sum_mat[i][j+1] + _sum_mat[i+1][j] - _sum_mat[i][j] + matrix[i][j]
                _sum_mat[i+1][j+1] = matrix[i][j] + _sum_mat[i][j+1] + _sum_mat[i+1][j] - _sum_mat[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // 总和等于左上角(0,0) 右下角 (row2, col2) 的矩阵 - (row2, col1) - (row1, col2) + (row1,col1)
        return _sum_mat[row2+1][col2+1] - _sum_mat[row2+1][col1] - _sum_mat[row1][col2+1] + _sum_mat[row1][col1];
    }
private:
    vector<vector<int>> _sum_mat;
};