void sort(int[] nums, int lo, int hi) {
    int mid = lo + (hi-lo)/2;
    sort(nums, lo, mid);
    sort(nums, mid+1, hi);
    merge(nums, lo, mid, hi);
}