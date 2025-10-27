/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define max(a, b) ((a) > (b) ? (a) : (b))
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int find(int *nums, int len, int target)
{
    for(int i = 0; i < len; i++)
    {
        if(nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int len = max(nums1Size, nums2Size);
    int *res = (int *)malloc(sizeof(int) * len);
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int i = 0;
    int j = 0;
    int cur = 0;
    while(i < nums1Size && j < nums2Size)
    {
        if(nums1[i] < nums2[j])
        {
            i++;
        }
        else if(nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            if(find(res, len, nums1[i]) == -1)
            {
                res[cur++] = nums1[i];
                
            }
            i++;
            j++;
        }
    }
    *returnSize = cur;
    return res;
}