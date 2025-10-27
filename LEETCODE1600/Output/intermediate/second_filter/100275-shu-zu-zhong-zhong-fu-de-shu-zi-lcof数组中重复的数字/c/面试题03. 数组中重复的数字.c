int findRepeatNumber(int* nums, int numsSize){
    int i;
    int iTmp;
    int aiNum[100000] = {0};

    for (i = 0; i < numsSize; i++)
    {
        iTmp = nums[i];
        aiNum[iTmp]++;
        if(2 <= aiNum[iTmp])
        {
            return iTmp;
        }
    }
    return 0;
}