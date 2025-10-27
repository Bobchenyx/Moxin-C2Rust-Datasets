void sortColors(int* nums, int numsSize){
    int i,j,tmp;
    int tmp0 = 0;
    int tmp1 = 0;
    int tmp2 = 0;


    for(i = 0;i < numsSize;i++)
    {
        if(nums[i] == 0)
        tmp0++;
        if(nums[i] == 1)
        tmp1++;
         if(nums[i] == 2)
        tmp2++;
    }
    for(j = 0;j < tmp0;j++)
    nums[j] = 0;
    for(j = 0;j < tmp1;j++)
    nums[tmp0 + j] = 1;
    for(j = 0;j < tmp2;j++)
    nums[tmp0+tmp1+j] = 2;

}