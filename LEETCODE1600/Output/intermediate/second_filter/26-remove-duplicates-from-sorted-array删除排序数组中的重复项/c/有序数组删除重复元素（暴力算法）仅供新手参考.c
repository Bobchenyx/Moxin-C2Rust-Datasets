int removeDuplicates(int* nums, int numsSize){
    int i,j,k;
    int count=numsSize;
    for(i=0;i<count;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(nums[j]==nums[i])
            {
                k=j;
                while(k<count-1)
                {
                    nums[k]=nums[k+1];
                    k++;
                }
                count--;
                j--;
            }
        }
    }
    return count;
}