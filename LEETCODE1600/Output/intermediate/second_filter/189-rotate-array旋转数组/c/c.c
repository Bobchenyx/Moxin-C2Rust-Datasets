void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    
    int *tmp = (int *)malloc(sizeof(int) * k);
    int i , j;
    
    for(i = 0; i < k; i++)
    {
        tmp[i] = nums[numsSize - k + i];
    }

    for(j = (numsSize - 1); j >= k; j--)
    {
        nums[j] = nums[j - k];
    }

    for(i = 0; i < k; i++)
    {
        nums[i] = tmp[i];
    }
}