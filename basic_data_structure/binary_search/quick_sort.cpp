#include <vector>
#include <algorithm>
#include <random>
using std::vector;
using namespace std;

// 快速排序其实就是个前序遍历，将当前的元素先摆正位置
// 之后再将左右剩余的部分进行同样的操作

void shuffle(vector<int>& nums) {
    random_device rd;
    default_random_engine rng(rd());
    std::shuffle(nums.begin(), nums.end(), rng);
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& nums, int lo, int hi) {
    int pivot = nums[lo];
    // 左右两个指针 开始遍历数组
    // 因为 pivot的 idx等于lo，所以从lo+1开始遍历
    int i = lo+1, j = hi;

    // 当 i>j 是结束循环，以保证区间[lo, hi]都被覆盖了
    // 即每个元素都被考虑到了。不然会出现 i == j这种情况下，i和j指向的元素没有被逻辑走到
    while (i <= j) {
        // 为什么是 < hi???
        while (i < hi && nums[i] <= pivot) {
            i++;
            // 此while结束的时候 nums[i] > pivot;
        }

        while (j > lo && nums[i] > pivot) {
            j--;
            // 此while结束的时候 nums[j] <= pivot;
        }

        // 为什么 i>= j 就break了？
        if (i >= j) {
            break;
        }
        // 注意这里的开闭区间
        // 此时 [lo, i) <= pivot && (j, hi] > pivot
        swap(nums[i], nums[j]);
        // 注意这里可能并没有 遍历完，知道整个大的while循环结束之后 这一段才“排序完整”
        // 此时 [lo, i] <= pivot && [j, hi] > pivot
    }
    // 为什么 return的是j? i不行吗？
    return j;
}

void sort(vector<int>& nums, int lo, int hi) {
    if (lo >= hi)
        return;
    // 对 nus[lo..hi] 进行切分
    // 使得 nums[lo..p-1] <= nums[p] < nums[p+1..hi]
    int p = partition(arr, lo, hi);

    // 去左右子数组进行切分
    sort(arr, lo, p-1);
    sort(arr, p+1, hi);
}

void sort(vector<int>& nums) {
    // 为了避免耗时的极端情况，先随机打乱
    shuffle(nums);
    sort(nums, 0, nums.size() - 1);
}