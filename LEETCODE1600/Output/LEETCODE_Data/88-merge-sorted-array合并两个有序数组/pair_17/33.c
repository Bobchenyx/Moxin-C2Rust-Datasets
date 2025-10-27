void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int len = m + n - 1;
    int i = m - 1, j = n - 1;
    if (m == 0) {
        for (int k = 0; k < n; ++k) {
            nums1[k] = nums2[k];
        }
        return;
    }
    while (i >=0 && j >= 0) {
        nums1[len--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }

    if (j >= 0) {
        for (int k = 0; k <= j; ++k) {
            nums1[k] = nums2[k];
        }
    }
}