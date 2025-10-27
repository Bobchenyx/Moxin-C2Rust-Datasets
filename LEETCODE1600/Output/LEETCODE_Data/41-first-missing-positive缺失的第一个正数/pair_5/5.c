int firstMissingPositive(int* nums, int numsSize){
	
	int top = 0, tail = 0;
	int cur = 0;
	
	while(cur < numsSize)
	{
		if(nums[cur] > 0 && nums[cur] <= numsSize)
		{
			if(cur >= (nums[cur] - 1))
			{
                if(nums[nums[cur] - 1] > 0)//不能重复标记
                {
                    nums[nums[cur] - 1] *= (-1);
                }
			}
			else
			{
				nums[tail++] = nums[tail] > 0 ? (nums[cur] - 1) : -(nums[cur] - 1);
			}
		}
		else
		{
			nums[cur] = INT_MAX;
		}
		cur++;
	}
	while(top < tail)
	{
		int index = nums[top] > 0 ? nums[top] : -nums[top];
        if( nums[index] > 0) //不能重复标记 
        {
            nums[index] *= -1;
        }
        
        top++;
	}
	for(int i = 0; i < numsSize; i++)
	{
		if(nums[i] > 0)
		{
			return i + 1;
		}
	}


    return numsSize + 1;
}