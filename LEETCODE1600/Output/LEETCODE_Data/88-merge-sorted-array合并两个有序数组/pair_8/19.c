void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i,j,temp;
    for(i=1;i<=n;i++)
        nums1[m+i-1]=nums2[i-1];
    for(i=0;i<m+n;i++)
    {
        for(j=i+1;j<m+n;j++)
        {
            if(nums1[i]>nums1[j])
            {
                temp = nums1[i];
                nums1[i] = nums1[j];
                nums1[j] = temp;
            }
        }
    }
}