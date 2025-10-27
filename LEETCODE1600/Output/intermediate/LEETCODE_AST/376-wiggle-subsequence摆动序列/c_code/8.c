int wiggleMaxLength(int* nums, int numsSize)
{
	int i;
	int ret=1;
	int flag=-1;
	if(numsSize<=2)
	{
		if(numsSize==2)
		{
			if(nums[0]==nums[1])
			{
				return 1;
			}
		}
		else
		{
			return numsSize;
		}
	}
	
	for(i=0;i<numsSize-1;i++)
	{
		if(nums[i+1]>nums[i])
		{
			if(flag==-1)
			{
				flag=0;
			}
			//第二个数大于第一个数(正负交替)
			if(flag==0)
			{
				flag=1;
				ret++;
			}
		}
		else if(nums[i+1]<nums[i])
		{
			if(flag==-1)
			{
				flag=1;
			}
			//第二个数小于第一个数(负正交替)
			if(flag==1)
			{
				flag=0;
				ret++;
			}
		}	
	}
    return ret;
}