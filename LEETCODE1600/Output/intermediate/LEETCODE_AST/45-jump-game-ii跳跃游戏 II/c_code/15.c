int jump(int* nums, int numsSize){
    int i,cout=1;
	int record = -1;
	int h = nums[0];
	if (numsSize == 1)
		return 0;
    if (nums[0] >= numsSize-1)
		return 1;
	for (i = 0; i < numsSize-1; i++)
	{
		if (i!=0&&i > record)
			return -1;
		if (i == h+1)
		{
			cout++;
			h = record;
		}
		if ((i + nums[i]) > record)
			record = i + nums[i];
		if (record >= numsSize-1)
			return cout+1;
	}
	return -1;
}