#include <vector>
using std::vector;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 首先排除第一格子都走不到的, 则他肯定不能作为起点
        vector<int> indexes;
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] < cost[i])
                continue;
            indexes.push_back(i);
        }

        for (auto begin: indexes) {
            // 这里的 begin是起点
            if (travel(gas, cost, begin)) 
                return true;
        }
        return false;
    }
private:
    bool travel(const vector<int>& gas, const vector<int>& cost, int begin) {
        int totalGas = 0;
        int n = gas.size();
        int end = begin+n;
        while(begin < end) {
            int idx = begin%n;
            totalGas += gas[idx];
            totalGas -= cost[idx];
            if (totalGas < 0)
                return false;
            begin++;
        }
        return true;
    }
};