int jump(int* nums, int numsSize){
	if (numsSize < 2)
		return 0;
	int step = 0;
    while (1){
        step++;
		if (*nums < numsSize - 1){
			int i, t = *nums, max = nums[t];
			for (i = 1; i <= *nums; i++)
				if (nums[i] + i >= max + t){
				max = nums[i];
				t = i;
				}
			nums = &nums[t];
			numsSize -= t;			
		}
		else
			break;		
	}
	return step;
}