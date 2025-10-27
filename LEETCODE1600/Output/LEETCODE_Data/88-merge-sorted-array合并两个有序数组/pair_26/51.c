void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i, j;
    for(i = m; i < m + n; i++){
        int temp = nums2[i - m];
        for(j = i; j>0 && nums1[j-1] > temp; j--)
            nums1[j] = nums1[j-1];
        nums1[j] = temp;
    }
}