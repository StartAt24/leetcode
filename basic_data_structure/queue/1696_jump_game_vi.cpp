#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        // 每次最多走k步，所以每次得寻找k中的最大值, 下一次再出发的时候是从上次的位置出发，寻找最大值
        int idx = 0;
        int n = nums.size();
        int ret = 0;
        while(idx < n) {
            map<int, int> temp;
            int count = k;
            int tempIdx = idx;
            while(count-- && tempIdx < n) {
                temp.insert({tempIdx, nums[tempIdx]});
                tempIdx++;
            }

            auto maxElement = std::max_element(temp.begin(), temp.end(), [](const auto& x, const auto& y){
                return x.second < y.second;
            });

            ret += maxElement->second;
            idx = maxElement->first + 1;
        }
        return ret;
    }
};