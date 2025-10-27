int massage(int* nums, int numsSize){
    int a=0,b=0,i=0;
    for(i;i<numsSize;i++)
    {
        int c = b>(a+nums[i])?b:(a+nums[i]);
        a=b;
        b=c;
    }
    return b;

}