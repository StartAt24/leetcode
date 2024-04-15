#include <vector>
using std::vector;

vector<int> preSum(vector<int> arr) {
    vector<int> res(arr.size()+1, 0);
    for (int i = 1; i <= arr.size(); i++) {
        res[i] = res[i-1] + arr[i-1];
    }

    return res;
}


// the sum of [left, right]
int rangeSum(vector<int> preSum, int left, int right) {
    // preSum[right+1] 是 [0, right] 的和
    // preSum[left] 是 [0, left-1]的和
    // 相减得到的即是 [left, right] 的和
    return preSum[right+1] - preSum[left];
}