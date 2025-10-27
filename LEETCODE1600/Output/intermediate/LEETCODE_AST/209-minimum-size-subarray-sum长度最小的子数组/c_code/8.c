#define MIN(X,Y)(X < Y ? X : Y)
int minSubArrayLen(int s, int* nums, int numsSize){
	
	int ret = INT_MAX;
	int head = 0, tail = 0;
	int temp = 0;
	
	while(tail <= numsSize) // 当tail ==numsSize时，仍然需要进行检查
	{
		while(temp >= s && head < tail)
		{
			ret = MIN(ret, tail - head);
			temp -= nums[head++];
		}
		
        if(tail == numsSize)
        {
            break;
        }

		temp += nums[tail++]; 
	}
	
	return ret == INT_MAX ? 0 : ret;
}