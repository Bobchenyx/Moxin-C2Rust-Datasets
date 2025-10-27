void rotate(int* nums, int numsSize, int k){
    int* num=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)
    {
        num[(i+k)%numsSize]=nums[i];
    }
    for(int i=0;i<numsSize;i++)
    {
        nums[i]=num[i];
    }
}