/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
        int *retnums =(int*)malloc(2*sizeof(int));
        memset(retnums, 0, sizeof(int) * 2);        
        *returnSize =0;
        for(int i=0;i<numsSize;i++)
        {
            for(int j=i+1;j<numsSize;j++)
            {
                if(target==nums[i]+nums[j])
                {
                    retnums[0]=i;
                    retnums[1]=j;
                    *returnSize=2;
                }
            }
        }
        return retnums;
}