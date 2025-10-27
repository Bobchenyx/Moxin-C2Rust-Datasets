double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if(nums1Size == 0 && nums2Size == 0)  //二者为空
        return 0;
    if(nums1Size == 0)  //1空
    {
        if(nums2Size % 2 != 0)  //奇数
        {
            int mid = (nums2Size - 1)/2;
            double ret = nums2[mid];
            return ret;
        }
        else
        {
            int mid = (nums2Size - 1)/2;
            double ret = (nums2[mid] + nums2[mid+1])/2.0;
            return ret;            
        }
    }
    if(nums2Size == 0)  //2空
    {
        if(nums1Size % 2 != 0)  //奇数
        {
            int mid = (nums1Size - 1)/2;
            double ret = nums1[mid];
            return ret;
        }
        else
        {
            int mid = (nums1Size - 1)/2;
            double ret = (nums1[mid] + nums1[mid+1])/2.0;
            return ret;            
        }
    }
    int len = nums1Size + nums2Size;
    int* a = (int*)malloc(sizeof(int) * len);
    int i = 0, q = 0, w = 0;
    double cur = 0;
    while(q < nums1Size || w < nums2Size)   //1 2 都不为空并且只要又一个不为空就继续
    {
        if((q < nums1Size && w < nums2Size) && (nums1[q] < nums2[w]))   //两者不为空，且 1 < 2
        {
            a[i++] = nums1[q];
            ++q;
        }
        else if((q < nums1Size && w < nums2Size) && (nums1[q] >= nums2[w])) //两者不为空，且 1 >= 2
        {
            a[i++] = nums2[w];
            ++w;            
        }
        else if(q >= nums1Size && w < nums2Size)
        {
            a[i++] = nums2[w];
            ++w;
        }
        else if(q < nums1Size && w >= nums2Size) 
        {
            a[i++] = nums1[q];
            ++q;
        }            
    }
    if(len % 2 !=  0)
    {
        int mid = (len - 1)/2;
        cur = a[mid];    
    }
    else
    {
        int mid = (len - 1)/2;
        cur = (a[mid] + a[mid + 1])/2.0;   //除2.0是因为a数组是整形，不想除2.0的话就把int强转一下
    }
    return cur;
}