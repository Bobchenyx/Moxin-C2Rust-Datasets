int rob(int* nums, int numsSize){
    int i;
    int num1 = 0, num2 = 0;

    for (i = 0; i < numsSize; i++) 
    {
        if (i % 2 == 0)
        {
            num1 += nums[i];
            num1 = num1 > num2 ? num1 : num2;
        }
        else
        {
            num2 += nums[i];
            num2 = num1 > num2 ? num1 : num2;
        }
    }

    return num1 > num2 ? num1 : num2;
}