// 冒泡排序
void sort(int * nums, int n)
{
    for(int  i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(nums[j] > nums[j + 1]){
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int k = 0;
    for(int i = m; i < m + n; i++){
        nums1[i] = nums2[k++];
    }
    sort(nums1, m + n);
}