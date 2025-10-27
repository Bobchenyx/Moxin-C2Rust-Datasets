void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i, j, k;
    int add_num = 0;

    if (n == 0) {
        return;
    }

    for (i = 0, j = 0; (i < m + add_num) && (j < n);) {
        if (nums1[i] <= nums2[j]) {
            i++;
        }
        else {
            for (k = m - 1 + add_num; k >= i; k--) {
                nums1[k + 1] = nums1[k];                
            }
            nums1[i] = nums2[j];
            add_num++;
            j++;
            i++;
        }
    }

    for (k = i; k < nums1Size; k++) {
        if (j < n) {
            nums1[k] = nums2[j++];
        }        
    }

}