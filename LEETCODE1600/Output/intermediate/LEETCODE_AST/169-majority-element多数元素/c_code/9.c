int majorityElement(int* nums, int numsSize)
{
	int count = 0, ans = 0;
	
	for(int i = 0; i < numsSize; i++)
	{
		if(nums[ans] == nums[i])
		count++;
		else
		count--;
		
		if(count == 0)
		ans = i+1;
		
		if(count > numsSize/2)
		break; 
	}
	return nums[ans];
}