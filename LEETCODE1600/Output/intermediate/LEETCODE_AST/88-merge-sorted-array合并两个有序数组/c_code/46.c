void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = m, j = 0; j < n; i++, j++){
        nums1[i] = nums2[j];
    }
    for(int i = 0; i < m + n; i++){//选择排序
        int k = i;
        for(int j = k; j < m + n; j++){
            if(nums1[k] > nums1[j]){
                k = j;
            }
        }
        int tmp = nums1[k];
        nums1[k] = nums1[i];
        nums1[i] = tmp;
    }
}
//方法二：
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p = m + n - 1, x = m - 1, y = n - 1;
    while(x >= 0 && y >= 0){
        nums1[p--] = nums1[x] > nums2[y] ? nums1[x--] : nums2[y--];
    }
    if(x < 0){
        while(y >= 0){
            nums1[p--] = nums2[y--];
        }
    }
}