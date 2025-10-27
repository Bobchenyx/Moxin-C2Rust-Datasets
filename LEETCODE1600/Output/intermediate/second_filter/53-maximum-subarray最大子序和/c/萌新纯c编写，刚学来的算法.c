int maxSubArray(int* nums, int numsSize)
{
int i,j=1;
int*mark=(int*)malloc(sizeof(int)*numsSize);
mark[0]=nums[0];
for(i=1;i<numsSize;i++)
	{
	mark[i]=mark[i-1]+nums[i]>nums[i]?nums[i]+mark[i-1]:nums[i];
	}
int result=mark[0];
while(j<numsSize)
	{
	if(mark[j]>result)
		result=mark[j];
	j++;
	}
return result;
}