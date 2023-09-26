// duplicate with 34
#include "../list/common.hpp"

class Solution {
public:
    int countTarget(vector<int>& scores, int target) {
        if (scores.size() == 0)
            return 0;

        int leftIdx = leftBoundry(scores, target);
        if (leftIdx == -1)
            return 0;
        
        int ret = 0;
        while(true) {
            if(scores[leftIdx] != target)
                break;
            ret++; 
            leftIdx++;
            if (leftIdx > scores.size()-1)
                break;
        }
        return ret;
    }
private:
    int leftBoundry(const vector<int>& scores, int target) {
        int left = 0, right = scores.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int val = scores[mid];
            if (val == target) {
                right = mid;
            } else if (val > target) {
                right = mid;
            } else if (val < target) {
                left = mid + 1;
            }
        }

        if (left > scores.size()-1 || left < 0)
            return -1;

        return scores[left] == target ? left : -1;
    }
};

int main()
{
    vector<int> score{1};
    Solution s{};
    int ret = s.countTarget(score, 1);
    return 0;
}