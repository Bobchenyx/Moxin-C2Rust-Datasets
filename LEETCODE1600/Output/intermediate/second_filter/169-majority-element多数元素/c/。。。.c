int majorityElement(int* nums, int numsSize)
{
    const int num = (int)(numsSize / 2 + 1);

    int arrayVal[num];
    int arrayNum[num];

    int indexAll = 0;

    for(int i = 0; i < numsSize; i++)
    {
        int addFlag = 1;
        for(int j = 0; j < indexAll; j++)
        {
            if(arrayVal[j] == nums[i])      
            {
                arrayNum[j]++;
                addFlag = 0;
                break;
            }
        }
        if(addFlag)
        {
            arrayVal[indexAll] = nums[i];
            arrayNum[indexAll] = 1;
            indexAll++;
        }
    }

    int ret = 0;
    for(int i = 0; i < indexAll; i++)
    {
        if(arrayNum[ret] <= arrayNum[i])        ret = i;
    }
    return arrayVal[ret];
}