void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int* a = (int*)malloc(sizeof(int)*m);
    int i=0,j=0,k=0;
    for(;i<m;i++)a[i]=nums1[i];//拷贝
    i=0;
    while(i<m&&j<n){//比较
        if(a[i]<nums2[j])nums1[k++]=a[i++];
        else nums1[k++]=nums2[j++];
    }
    if(i==m) while(j<n)nums1[k++]=nums2[j++];//后续比较
    else while(i<m)nums1[k++]=a[i++];
    m = m+n;
}