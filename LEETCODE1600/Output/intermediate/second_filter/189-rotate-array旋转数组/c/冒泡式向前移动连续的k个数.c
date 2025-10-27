void rotate(int* nums, int numsSize, int k){
    
    if(k>numsSize)
        k=k%numsSize;
    if(k==0||k==numsSize)
        return;
    int j=1;
    while(j<(numsSize/k))
    {

        for(int i=numsSize-j*k-1;i>numsSize-j*k-1-k;--i)
        {
            int temp=nums[i+k];
            nums[i+k]=nums[i];
            nums[i]=temp;
        }
        ++j;
    }
    for(int i=numsSize-j*k-1;i>=0;--i)
    {
        for(int m=i;m<i+k;m++)
        {
            int temp=nums[m];
            nums[m]=nums[m+1];
            nums[m+1]=temp;
        }
    }
}