int pivotIndex(int* nums, int numsSize)
{
    int i;
    int j;
    int sum1 = 0;
    int sum2 = 0;
    
    for (i = 0; i < numsSize; i++) {
        sum1 += nums[i];
        for (j = i; j < numsSize; j++) {
            sum2 += nums[j];
        }
        
        if (sum1 == sum2) {
            return i;            
        }  

        sum2 = 0;
    }

    return -1;
}