#include "common.hpp"
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // 将二维数组展开成一维度,然后 平移之后 计算他的平移之后的indx，再还原回去
        int w = grid[0].size();
        int h = grid.size();
        vector<vector<int>> res(h);
        for(auto& vec: res){
            vec.resize(w);
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j ++) {
                auto position = extend(j, i, k, w, h);
                res[position[1]][position[0]] = grid[i][j];
            }
        }
        return res;
    }
private:
    vector<int> extend(int x, int y, int k, int w, int h){
        int absIndx = y*w + x;
        int afterIndx = absIndx + k;
        afterIndx %= (w*h);

        int retX = afterIndx%w;
        int retY = afterIndx/w;
        return vector<int>{retX, retY};
    }
};