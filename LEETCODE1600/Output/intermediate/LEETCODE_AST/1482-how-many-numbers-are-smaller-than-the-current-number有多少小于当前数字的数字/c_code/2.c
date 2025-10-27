/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
   int* result=(int*)malloc(sizeof(int)*numsSize);
    int i=0;
    for(i=0;i<numsSize;++i)
        result[i]=0;
    for(i=0;i<numsSize;++i)
    {
        int j=0;
        for(j=0;j<numsSize;++j)
            if(nums[j]<nums[i]&&i!=j)
                ++result[i];
    }
    *returnSize=numsSize;
    return result;
}