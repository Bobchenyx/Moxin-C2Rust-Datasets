void rotate(int* nums, int numsSize, int k){
    if(NULL == nums || 0 == numsSize)
    {
        return;
    }
    
    int a[numsSize];

    for(int i = 0 ;i < numsSize;i++)
    {
        a[i] = nums[i]; 
    }

    for(int i = 0 ;i < numsSize;i++)
    {
        nums[(i+ k)%numsSize] = a[i]; 
    }
}