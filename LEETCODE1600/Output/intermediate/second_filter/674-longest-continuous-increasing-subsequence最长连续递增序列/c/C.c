int findLengthOfLCIS(int* nums, int numsSize){
if(numsSize==0)
return 0;
int length = 1;
	int len = 1;
	int i = 1;
	for (i; i < numsSize; i++)
	{
		if (nums[i] > nums[i - 1])
			len++;
		else
			len = 1;
		if (len > length)
			length = len;
	}
	return length;
}