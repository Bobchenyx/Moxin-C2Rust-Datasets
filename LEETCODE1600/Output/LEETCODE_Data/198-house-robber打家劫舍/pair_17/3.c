int rob(int* nums, int numsSize){
    int curMax = 0;
    int preMax = 0;
    int temp = 0;
    int index = 0;

    for (index = 0; index <= numsSize - 1; index++)
    {
        temp = curMax;
        curMax = preMax + nums[index] > curMax ? preMax + nums[index] : curMax;
        preMax = temp;
    }

    return curMax;
}