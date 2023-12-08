#include <vector>
#include <iostream>
using namespace std;


void print(vector<int> arr, int i) {
    if (i == arr.size())
        return;
    cout << arr[i] << endl;
    return print(arr, i + 1);
};

int find(vector<int> arr, int i, int target) {
    if (i == arr.size())
        return -1;
    
    if (arr[i] == target)
        return i;

    return find(arr, i+1, target);
}