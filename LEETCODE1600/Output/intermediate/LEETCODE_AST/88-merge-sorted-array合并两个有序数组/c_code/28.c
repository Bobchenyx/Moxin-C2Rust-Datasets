void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int tail=m+n-1,tail1=m-1,tail2=n-1;  
    while(tail!=tail1)
        nums1[tail--]=
        tail1>=0 &&  nums1[tail1]>nums2[tail2] ? nums1[tail1--] : nums2[tail2--];
    }