int singleNumber(int* nums, int numsSize){
    if(NULL == nums || 0 == numsSize)
    {
        return 0;
    }

    int ans = 0;

    for(int i = 0;i < numsSize ;i++)
    {   
        ans ^= nums[i];
    }

    return ans;
}