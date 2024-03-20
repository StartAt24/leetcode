#include <vector>
// quick sort n*log(n)
using std::vector;
void QuickSort(vector<int>& arr, int L, int R) {
    if (L>=R)
        return;

    int l = L, r = R;
    int pivot = arr[l];
    while (l < r) {
        // the first step should be right go first in order to match the last switch operation
        while(l<r && arr[r] >= pivot) {
            r--;
        }
        // move the small one to left;
        if (l<r) {
            arr[l] = arr[r];
        }
        while(l < r && arr[l] <= pivot) {
            l++;
        }

        // move the big one to right;
        if (l < r) {
            arr[r] = arr[l];
        }
        
        if (l >= r) {
            arr[l] = pivot;
        }
    }
    // 递归的去排序剩余的左右部分
    QuickSort(arr, L, r-1);
    QuickSort(arr, r+1, R);

}