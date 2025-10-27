int singleNumber(int* nums, int numsSize){
    int a = 0;
    int b = 0;

    for(int i = 0;i < numsSize;i++)
    {
        b = (b ^ nums[i]) & ~a;
        a = (a ^ nums[i]) & ~b;
    }

    return b;
}