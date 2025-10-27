void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
int i,j,c;
for(i=0;i<n;i++)
    nums1[m+i]=nums2[i];
int count=m+n;
for(i=0;i<count-1;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(nums1[i]>nums1[j])
            {
                c=nums1[i];nums1[i]=nums1[j];nums1[j]=c;
            }
        }
    }
}