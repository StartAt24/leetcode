#include <vector>
#include <algorithm>
using std::vector;

// h-index即 >=h个的值 >=h

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left)/2;
            int cnt = NumGreaterThan(citations, mid);
            // 如果符合条件,则尽量向右边移动
            if (cnt == mid) {
                left = mid + 1;
            } else if ( cnt < mid) {
                // 向左边移动
                right = mid; 
            } else if (cnt > mid) {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    int NumGreaterThan(const vector<int>& citations, int n) {
        return std::count_if(citations.begin(), citations.end(), [n](int i) {
            return i>=n;
        });
    }
};