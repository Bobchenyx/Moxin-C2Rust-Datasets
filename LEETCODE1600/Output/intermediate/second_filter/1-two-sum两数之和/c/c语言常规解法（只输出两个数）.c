/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if(numsSize==0)
    {
        return NULL;
    }
    int cnt;
    int* num=(int*)malloc(sizeof(int)*numsSize);
    *returnSize=2;
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                num[cnt++]=i;
                num[cnt++]=j;
                return num;
            }
        }
    }
    return NULL;
}