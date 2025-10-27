int pivotIndex(int* nums, int numsSize){
    int i,j;
    int s=0,t=0;
    if(NULL == nums||numsSize < 2){
        return -1;
    }
    for(i=0;i<numsSize;i++)
    {
        s+=nums[i];
    }
    for(i=0;i<numsSize;i++)
    {
        
        if(t*2+nums[i]==s)
        {
            return i;
        }
        t+=nums[i];
    }
    return -1;
}