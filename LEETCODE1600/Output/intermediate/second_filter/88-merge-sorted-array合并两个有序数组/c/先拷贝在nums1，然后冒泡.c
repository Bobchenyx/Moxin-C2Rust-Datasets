void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i=0,j=m;i<n;i++,j++){
        nums1[j]=nums2[i];
    }
    for(int i=0;i<m+n;i++){
        for(int j=m+n-1;j>i;j--){
            if(nums1[j]<nums1[j-1]){
                int temp=nums1[j];
                nums1[j]=nums1[j-1];
                nums1[j-1]=temp;
            }
        }
    }
}