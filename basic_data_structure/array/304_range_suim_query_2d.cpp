#include "common.hpp"

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        if ( rows == 0 || cols == 0)
            return;

        _sum_matrix.resize(rows+1);
        for ( auto& line: _sum_matrix) {
            line.resize(cols+1);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                _sum_matrix[i+1][j+1] = _sum_matrix[i][j+1] + _sum_matrix[i+1][j] + matrix[i][j] - _sum_matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // top-left : row1, col1
        // bottom-right: row2, col2
        int minus1_top = _sum_matrix[row2+1][col2+1] - _sum_matrix[row1][col2+1] - _sum_matrix[row2+1][col1] + _sum_matrix[row1][col1];
        return minus1_top;
    }
private:
    vector<vector<int>> _sum_matrix;
};