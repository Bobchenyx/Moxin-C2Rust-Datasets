int maxSubArray(int* nums, int numsSize){

    if (numsSize == 0)
    {
        return NULL;
    }

    int maxNum = nums[0];
    int sum = 0;
    int i = 0;
    int sumMax = nums[0];

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > maxNum)
        {
            maxNum = nums[i];
        }

        sum += nums[i];//累加

        if (sumMax < sum)//记录最大的序列和
        {
            sumMax = sum;
        }

        if (sum < 0)//序列和小于0，抛弃
        {
            sum = 0;
        }
    }

    if (sumMax < maxNum)//没有正数序列和的问题。没有正数，则sum == 0，显然是错的。此时maxNum记录最大的负数。
    {
        sumMax = maxNum;
    }

    return sumMax;

}