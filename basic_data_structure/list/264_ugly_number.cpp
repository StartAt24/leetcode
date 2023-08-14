#include "common.hpp"

class Solution {
    int nthUglyNumber(int n) {
        // so the numer is combination of 2*2*... or 2*3*x or 2*5*
        // three list
        // 2, 2, 2, 2, 2
        // 3, 3, 3, 3, 3
        // 5, 5, 5, 5, 5
        // put into a 
        int idxTwo = 0, idxThree = 0, idxFive=0;
        vector<int> ret;
        ret.reserve(n);
        ret.push_back(1);
        int basic = 1;
        int p_2 = 0, p_3 = 0, p_5 = 0;

        // we need n_th number
        for (int i = 0; i <n; i++){
            // get one from each list and compare them; 
            // get p_2 element from the 2-list;
            int val = 1;
            
            // get one extra val from the list and compare them



            int val3 = 1;
            for (int j = 0; j <= p_3; j++)
                val3*=3;
            // get p_3 element from the 3-list; 
            // get p_5 element from the 5-list;
            int val3 = basic*5;

        }

    }
};