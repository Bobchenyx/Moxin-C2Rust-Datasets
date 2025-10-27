void resverarr(int *nums, int left, int right);


void rotate(int* nums, int numsSize, int k){
    if(k%numsSize)
    {
        while(k>numsSize)
            k-=numsSize;

        resverarr(nums,0,numsSize-k-1);
        resverarr(nums,numsSize-k,numsSize-1);
        resverarr(nums,0,numsSize-1);
        
    }
}

void resverarr(int *nums, int left, int right)
{
    int mid=(left+right)/2;
    int temp;

    for(int i=0;i<=mid-left;i++)
    {
        temp=nums[left+i];
        nums[left+i]=nums[right-i];
        nums[right-i]=temp;
    }
}