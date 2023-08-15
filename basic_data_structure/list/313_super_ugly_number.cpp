#include "common.hpp"

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ret(n);
        ret.push_back(1);

        int loop = n - 1;
        while(loop--){
            // we need the minimalist
            std::priority_queue<int, vector<int>, std::greater<int>> minHeap;
            // so there are primes.size() lists;
            // the idx for each list, default as 1;
            vector<int> idx(primes.size(), 1);

            for (auto i = 0; i < primes.size(); i++) {
                minHeap.push(ret[idx[i]] * primes[i]);
            }

            int minVal = minHeap.top();
            // increase the idx that matches with minval;
            for (auto i = 0; i < primes.size(); i++) {
                if (minVal == ret[idx[i]] * primes[i]){
                    idx[i]++;
                }
            }
            ret.push_back(minVal);
        }
        return ret[n-1];
    }
};