#include "common.hpp"

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglyNumbers;
        uglyNumbers.push_back(1);
        // pointer of each list;
        vector<int> idx(primes.size(), 0);

        int loop = n - 1;
        int current = 0;
        while(loop--){
            // we need the minimalist
            // so there are primes.size() lists;
            // the idx for each list, default as 1;
            std::priority_queue<int, vector<int>, std::greater<int>> minHeap;
            for (auto i = 0; i < primes.size(); i++) {
                // 下一轮的时候不可能再添加重复的项目了
                int val = uglyNumbers[idx[i]] * primes[i];
                val = min(std::numeric_limits<int>::max(), val);
                minHeap.push(val);
            }

            int minVal = minHeap.top();
            // increase the idx that matches with minval;
            for (auto i = 0; i < primes.size(); i++) {
                if (minVal == uglyNumbers[idx[i]] * primes[i]) {
                    idx[i]++;
                }
            }
            current++;
            uglyNumbers.push_back(minVal);
        }
        return uglyNumbers[n-1];
    }
};

int main(){
    Solution s;
    std::vector<int> primes;
    primes.push_back(2);
    primes.push_back(7);
    primes.push_back(13);
    primes.push_back(19);
    s.nthSuperUglyNumber(12, primes);
    return 0;
}