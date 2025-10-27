int singleNumber(int* nums, int numsSize){
    int  i = 0, sum = 0;
    for(i = 0; i < numsSize; i++)
    {
        sum = sum ^ nums[i];
    }
    return sum;
}