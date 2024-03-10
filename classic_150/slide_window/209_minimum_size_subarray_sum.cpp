#include <vector>
using namespace std;

class Window{
public:
    void push(int n) {
        _max += n;
        _size++;
    }

    int sum() {
        return _max;        
    }

    void pop(int n) {
        _max -= n;
        _size--;
    }

    int size() {
        return _size;
    }

private:
    int _size = 0;
    int _max = 0;     
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int minSize = nums.size()+1;

        while (right < nums.size()) {
            _win.push(nums[right]);

            while(_win.sum() >= target) {
                minSize = min(_win.size(), minSize);
                _win.pop(nums[left]);
                left++;
            }
            right++;
        }

        if (minSize == nums.size()+1)
            return 0;

        return minSize;
    }
private:
    Window _win; 
};