/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i=0,j=numsSize-1;
    int *ans=(int*)malloc(sizeof(int)*2);
    ans[0]=0;
    ans[1]=0;
    *returnSize = 2;
    while(i<j)
    {
        if(nums[i]+nums[j]==target)
        {
            ans[0]=nums[i];
            ans[1]=nums[j];
            return ans;
        }
        else if(nums[i]+nums[j]>target)
        {
            j--;
        }
        else 
        {
            i++;
        }
    }
    return ans;
}