int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0)
    return 0;
	int count = 1;
	int t = nums[0];
	for (int i = 1; i <=numsSize-1; i++)
	{
		if (nums[i]==t) {
			continue;
		}
		else
		{
			nums[count] = nums[i];
			t = nums[i];
			count++;
		}
	}
	return count;
}