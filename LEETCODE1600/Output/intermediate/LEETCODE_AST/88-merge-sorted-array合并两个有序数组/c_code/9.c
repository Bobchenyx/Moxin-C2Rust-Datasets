void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        while(nums1[j]<nums2[i]&&j<m+i)
        {
            j++;
        }
        if(j<m+i)
        {
            int q=m+i;
            for(q;q>j;q--)
            {
                nums1[q]=nums1[q-1];
            }
            nums1[j]=nums2[i];
        }else{
            for(;i<n;i++)
            {
                nums1[j++]=nums2[i];
                break;
            }
        }

    }
}