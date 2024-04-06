#include<vector>

using namespace std;

void Merge(vector<int>& arr, int lo, int mid, int hi) {
    int p1 = lo;
    int p2 = mid+1;
    // 1,3, 2,4
    // p1,  p2
    


    while(1) {
        if (arr[p1] <= arr[p2]) {
            p1++;
        } else {
            arr[p1] = arr[p2];
            p2++;
        }


    }

    return;
}

void MergeSort(vector<int>& arr) {

}

