int minSubArrayLen(int s, int* nums, int numsSize){
    int head=0,rear=0,sum=0;
    int min=numsSize+1;
    while(head<numsSize)
    {
        sum+=nums[head++];//head永远指向即将要加的元素
        while(rear<head&&(sum-nums[rear])>=s)
            {
            sum-=nums[rear++];
            }
        if(sum>=s&&(head-rear)<min)
        min=(head-rear);
    }
    if(min==numsSize+1)
    return 0;
    return min;
}