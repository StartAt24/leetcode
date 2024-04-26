#include <vector>
#include <queue>
using std::vector;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int ,vector<int>, std::less<int>> maxHeap;
        for(auto n : nums) {
            maxHeap.insert(n);
        }

        while (k--) {
            maxHeap.pop();
        }

        return maxHeap.top() 
    }
};      