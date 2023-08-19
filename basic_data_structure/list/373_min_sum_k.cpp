#include "common.hpp"
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        struct Element{
            Element(int val1, int val2, int idx):val1(val1), val2(val2), idx(idx) {
                sum = val1+ val2;
            }
            vector<int> get() {
                return vector<int> {val1, val2};
            }

            int sum;
            int val1;
            int val2;
            // store the current idx of list2?
            int idx = 0;
            bool operator>(const Element& other) const {
                return this->sum > other.sum;
            }
        };
        // merge nums1 * nums2 's list
        std::priority_queue<Element, std::vector<Element>, std::greater<Element>> minHeap;
        // initialize minHeap;

        // 取每个队列的第一个元素
        // 可以有两种生成队列的方式: nums1的所有元素和 nums2的第一个元素  或者 nums1的第一个元素和 nums2的所有元素
        for (int i = 0; i < nums1.size(); i++) {
            minHeap.push(Element(nums1[i], nums2[0], 0));
        }

        int idxLimit = nums2.size();
        vector<vector<int>> res;
        // 为什么要非空?
        while (!minHeap.empty() && k > 0) {
            // loop over all lists;
            // put it's element into the minHeap;
            auto current = minHeap.top();
            k--;
            res.push_back(current.get());
            if (current.idx < nums2.size()-1)
                minHeap.push(Element(current.val1, nums2[current.idx+1], current.idx+1));
            minHeap.pop();
        }

        return res; 
    }
};