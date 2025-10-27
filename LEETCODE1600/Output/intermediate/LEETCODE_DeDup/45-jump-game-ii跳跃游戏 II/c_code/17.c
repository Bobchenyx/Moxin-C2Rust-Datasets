int jump(int* nums, int numsSize){
    int *index;
    index = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i ++)
    {
        index[i] = nums[i] + i;
    }

    if (numsSize < 2)
        return 0;


    int currMaxIndex = index[0];
    int tmpMaxIndex = index[0];
    int jumpTimes = 1;

    for (int j = 0; j < numsSize; j ++)
    {
        if (j > currMaxIndex)
        {
            jumpTimes ++;
            currMaxIndex = tmpMaxIndex;
        }
        if(tmpMaxIndex < index[j])
        {
            tmpMaxIndex = index[j];
        }
    }

    return jumpTimes;
}