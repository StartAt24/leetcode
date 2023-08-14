#include "common.hpp"

class Solution {
    int nthUglyNumber(int n) {
        // three lists
        // 1*2, 2*2, 3*2, 4*2, 5*2, 6*2, 8*2...
        // 1*3, 2*3, 3*3, 4*3, 5*3, 6*3, 8*3...
        // 1*5, 2*5, 3*5, 4*5, 5*5, 6*5, 8*5...
        // merge those three list.
        // !!!remember to use the array that generated during the process.
        int p2 = 0, p3 = 0, p5=0;
        int next2 = 0, next3 = 0, next5 = 0;
        vector<int> ret;
        ret.reserve(n);
        ret.push_back(1);

        for (int i = 1; i < n; i++) {
            next2 = ret[p2]*2;
            next3 = ret[p3]*3;
            next5 = ret[p5]*5;

            // 注意这里有去重的操作！！！
            // 所以都是 if 而没有else, 当相同值出现时，同时跳过其他链表上的这个值
            ret[i] = std::min({next2, next3, next5});
            if (ret[i] == next2){
                p2++;
            }

            if (ret[i] == next3){
                p3++;
            }

            if (ret[i] == next5){
                p5++;
            }
        }
        return ret[n-1];
    }
};