int findRepeatNumber(int *nums, int numsize)
{
    int hashMap[numsize];
    for(int i=0; i< numsize; i++)
    {
        hashMap[i]=0;
    }
    for (int i=0; i<numsize; i++)
    {
        hashMap[nums[i]]++;
        if(hashMap[nums[i]] > 1)
            return nums[i];
    }
    return 0;
}