//贪心算法.O(n)
int maxSubArray(int* nums, int numsSize){

    int sum = 0;
    int ans = nums[0]-1;    //小技巧
    for(int i = 0; i < numsSize; i++)
    {
        sum += nums[i];

        if(sum > ans)   
            ans = sum;
        if(sum < 0)     //小于0，舍弃，重新开始累积
            sum = 0;
    }
    return ans;
}