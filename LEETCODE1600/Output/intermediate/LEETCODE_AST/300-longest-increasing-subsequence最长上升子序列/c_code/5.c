int lengthOfLIS(int* nums, int numsSize){
    int length = 0;
    int i = 0, j = 0;
    int *arr = (int *)malloc(sizeof(int) * numsSize);

    if(!numsSize)
    {
        return 0;
    }

    arr[0] = nums[0];
    length = 1;

    for(i = 1; i < numsSize; i++)
    {
        if(nums[i] > arr[length - 1])
        {
            length++;
            arr[length - 1] = nums[i];
        }
        else
        {
            for(j = (length - 2); j >= 0; j--)
            {
                if(arr[j] < nums[i])
                {
                    arr[j + 1] = nums[i];
                    break;
                }
            }

            if(j == -1)
            {
                arr[0] = nums[i];
            }
        }
    }

    return length;
}