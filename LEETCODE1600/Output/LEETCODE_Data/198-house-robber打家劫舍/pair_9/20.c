int max(int a,int b){
    if(a > b)
        return a;
    else
        return b;
}
int rob(int* nums, int numsSize){
    if(numsSize < 1)
        return 0;
    if(numsSize == 1)
        return nums[0];
    int a[numsSize];
    a[0] = nums[0];
    a[1] = max(nums[0],nums[1]);
    for(int i = 2;i < numsSize;++i){
        a[i] = a[i - 1];
        a[i] = max(a[i],(a[i - 2] + nums[i]));
    }
    return a[numsSize - 1];
}