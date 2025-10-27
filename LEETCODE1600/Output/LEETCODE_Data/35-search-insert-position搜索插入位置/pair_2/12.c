int searchInsert(int* nums, int numsSize, int target)
{
int i;
int count=-1;
int*mark=(int*)malloc(sizeof(int)*numsSize);
for(i=0;i<numsSize;i++)
    {
        if(nums[i]<target)
            {
                mark[++count]=nums[i];
            }
    }
if(count==-1)
return 0;
return (count+1);
}