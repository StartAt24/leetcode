#include<vector>

using namespace std;

void Merge(vector<int>& arr, int lo, int mid, int hi) {
    // 1,3, 2,4
    // p1,  p2
    int size = hi-lo+1;
    vector<int> temp(size);

    int p1 = lo;
    int p2 = mid+1;

    for (int i = 0; i < size; i++) {
        // 这里不能单纯的用双指针去遍历两者，要考虑到其中一个遍历结束的情况
        // 左侧已经
        if (p1 == mid+1) {
            temp[i] = arr[p2++];
        } else if (p2 == hi) {
            temp[i] = arr[p1++];
        } else if (arr[p1] < arr[p2]) {
            temp[i] = arr[p1++];
        } else {
            temp[i] = arr[p2++];
        }
    }

    std::copy(temp.begin(), temp.end(), arr.begin()+lo);
    return;
}

void MergeSort(vector<int>& arr) {
    MergeSort(arr, 0, arr.size()-1);
}

void MergeSort(vector<int>& arr, int lo, int hi) {
    if(lo == hi)
        return;
    int mid = lo + (hi-lo)/2;
    MergeSort(arr, lo, mid);
    MergeSort(arr, mid+1, hi);

    Merge(arr, lo, mid, hi);
}

