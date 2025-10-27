//用桶排序写写
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
int bucket[101];
int* ans=(int*)malloc(sizeof(int)*numsSize);
*returnSize=numsSize;
int i;
//桶里元素清零
for(i=0;i<101;i++)
{
    bucket[i]=0;
}
//往桶里装东西
for(i=0;i<numsSize;i++)
{
    bucket[nums[i]]++;
}

int sum=0,j=0;
for(i=0;i<numsSize;i++)
{
    for(j=0;j<nums[i];j++)
    {
        sum=sum+bucket[j];
    }
    ans[i]=sum;
    sum=0;
}
return ans;
}