void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = 0; i < n ; i++){
        int j = m-1; // j指向nums1的最后一个元素的位置
        for(;j>=0;j--){
            if(nums2[i]<nums1[j]){
                nums1[j+1]=nums1[j];//如果要是j的位置大于i的位置的值说明i的插入位置在前面，所以将j的元素的位置的值向后移；
            }
            else{break;}
        }//到这里已经找到了i插入的位置即j+1处
        //原因是j--是已经执行过的，需要对其进行+1恢复正确位置
        nums1[j+1]=nums2[i];
        m++;//插入之后m的长度应该也加1才对，因为一个元素插入了
    }
}