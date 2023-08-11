#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // the input is sorted, increasement
        // index started with 1
        int left = 0, right = numbers.size()-1;
        vector<int> ret{};
        while(left < right) {
            int l = numbers[left];
            int r = numbers[right];
            int current = l + r;
            if (target == current) {
                ret.push_back(left+1);
                ret.push_back(right+1);
                return ret;
            }
            else if (target < current) {
                right--;
            } else if (target > current) {
                left++;
            }
        }
        return ret;
        // the return value needs to add 1 to match the whole index; 
    }
};