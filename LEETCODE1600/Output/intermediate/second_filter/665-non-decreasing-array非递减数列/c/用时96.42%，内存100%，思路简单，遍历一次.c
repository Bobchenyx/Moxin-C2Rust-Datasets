bool checkPossibility(int* nums, int numsSize){
	int i,t=0;   //t用于记录可改变数的个数，先置0
    int n=numsSize;  //为书写方便
    if(n<=3)   //小于3的情况不再赘述
    {       
        for(i=0;i<n-1;i++) {
            if(nums[i]>nums[i+1])
                t++;
        }
        if(t==2)
	    return false;
	    else
	    return true;
    }
    else   //n>3
	{
    if(nums[0]>nums[1])
	t++;
	if(nums[n-1]<nums[n-2])  //检查首尾
	t++;
	for(i=1;i<n-2;i++) 
    {
		if(t==2) 
			return false; 
		if(nums[i]>nums[i+1]) 
        {
			if(nums[i]>nums[i+2]&&nums[i+1]<nums[i-1])
			return false;
			else
			t++;
		}
	}
	if(t==2)
	return false;
	else
	return true;
    }
}