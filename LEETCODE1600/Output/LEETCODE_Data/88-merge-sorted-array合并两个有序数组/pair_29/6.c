void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = 1; i <= m; i++) {
        nums1[nums1Size - i] = nums1[m - i];
    }
    int p1 = nums1Size - m,p2 = 0;
    for(int i = 0; i < nums1Size; i++) {
        if(p2 < n && p1 < nums1Size){
            nums1[i] = (nums1[p1] < nums2[p2])?nums1[p1++]:nums2[p2++];
        } 
        else if(p1 == nums1Size) {
            nums1[i] = nums2[p2++];
        }
    }
}