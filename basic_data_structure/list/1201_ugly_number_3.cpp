#include "common.hpp"

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        // pointer of each list
        int idxA = 1, idxB = 1, idxC = 1;
        vector<int> ugly;
        ugly.reserve(n);
        // the min is the first element;
        // three lists looks like
        // ax1 ax2 ax3 ax4 ax5
        // bx1 bx2 bx3 bx4 bx5
        // cx1 cx2 cx3 cx4 cx5
        while(n--) {
            int val_a = idxA*a;
            int val_b = idxB*b;
            int val_c = idxC*c;

            int minVal = std::min({val_a, val_b, val_c});
            ugly.push_back(minVal);
            
            if(minVal == val_a)
                idxA++;
            if(minVal == val_b)
                idxB++;
            if(minVal == val_c)
                idxC++;
        }
        return ugly.back();
    }
};