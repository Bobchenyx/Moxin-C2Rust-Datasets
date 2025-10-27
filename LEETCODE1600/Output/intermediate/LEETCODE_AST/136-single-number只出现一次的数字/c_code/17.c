int singleNumber(int* nums, int numsSize){
    int i=0,a=0;
    for(i=0;i<numsSize;i++)
    {
       a ^=nums[i];
    }
    return a;

}