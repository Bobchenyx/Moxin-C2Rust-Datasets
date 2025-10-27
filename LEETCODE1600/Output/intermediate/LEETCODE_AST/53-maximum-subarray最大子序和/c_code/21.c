int maxSubArray(int* nums, int numsSize){

   	int i,n;
	int ThisSum, MaxSum,min;
	ThisSum = MaxSum = 0;
	
	if(numsSize <= 0)
		return 0;
	if(numsSize == 1)
		return nums[0];

	n = 0;
    min = nums[0];
	for(i=n;i<numsSize;i++)
	{
		if(nums[i] <= 0)
        {
            if(nums[i] > min)
                min = nums[i];
			n++;
        }
		else
			break;
	}

	if(n == numsSize)
		return min;

	for( i = n; i < numsSize; i++ ) 
	{
		ThisSum += nums[i]; 
		if( ThisSum > MaxSum)
			MaxSum = ThisSum; 
		else if( ThisSum < 0 ) 
			ThisSum = 0; 
	}
    return MaxSum;
}