int removeElement(int* nums, int numsSize, int val)
{
	int i;
	int j;
	int m=0;
	for(i=0;i<numsSize-m;)
	{
		if(nums[i]==val)
		{
			if(i==numsSize-m)
			{
				return numsSize-m;
			}
			for(j=i;j<numsSize-1;j++)
			{
				nums[j]=nums[j+1];
			}
            m++;
		}
		else
		{
			i++;
		}
	
	}
    return numsSize-m;
}