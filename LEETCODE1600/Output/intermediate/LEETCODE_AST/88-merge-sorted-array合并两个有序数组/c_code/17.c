void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if(nums1Size == 0 || nums2Size == 0 || n == 0)
        return;
    if(m == 0){
        for(int i = 0; i < n; i++){
            nums1[i] = nums2[i];
        }
        return;
    }
    int i, j, l = m;
    for(i = 0; i < n; i++){
        for(j = l - 1; j >= 0 && nums1[j] > nums2[i]; j--){
            nums1[j+1] = nums1[j];
        }
        nums1[j+1] = nums2[i];
        l++;   //每次插入后nums1有序部分长度加1
    }
}