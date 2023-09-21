#include "common.hpp"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size()*matrix[0].size()-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int current = get(matrix, mid);
            if ( current== target){
                return true;
            }
            else if (current > target) {
                right = mid - 1;
            } else if ( current < target) {
                left = mid + 1;
            }
        }
        return false;
    }
private:
    int get(const vector<vector<int>>& matrix, int idx) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = idx / n;
        int col = idx % n;
        int val = matrix[row][col];
        return val;
    }
};