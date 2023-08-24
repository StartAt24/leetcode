#include "common.hpp"
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 以对角线旋转一次，然后再将每一行翻转，则就变成了 旋转90度
        // 矩阵 n*n;
        int n = matrix.size();

        // 从对角线对折一次
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // 逐行reverse
        for (int i = 0; i < n; i++) {
            reverse(matrix[i]);
        }
    }
private:
    void reverse(std::vector<int>& line) {
        int l = 0, r = line.size()-1;
        while (l<r) {
            int temp = line[l];
            line[l] = line[r];
            line[r] = temp;
            l++;
            r--;
        }
    }
};