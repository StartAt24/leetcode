#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // find val in nums2;
        vector<int> ret;
        for(int i = 0; i < nums1.size(); i++) {
            int current = nums1[i];
            auto found = std::find(nums2.begin(), nums2.end(), current);
            if (found != nums2.end()) {
                while(found != nums2.end()) {
                    int val = *found;
                    if (val > current) {
                        ret.push_back(val);
                        break;
                    }
                    found++;
                }

            }
            if (found== nums2.end()) {
                ret.push_back(-1);
            }
        }

        return ret;
    }
};