int jump(int* nums, int numsSize) {
	int* jump_min = (int*)malloc(sizeof(int)*numsSize);
	int min = -1; 
	int last = numsSize - 1;
	jump_min[numsSize - 1] = 0;
	int res = -1;
	for (int i = numsSize-2; i >= 0; i--) {
		if ((nums[i] + i) >= (numsSize - 1)) {
			jump_min[i] = 1;
			last = i;
		}else if (last > (nums[i] + i)) {
			jump_min[i] = -1;
		}
		else {
			min = jump_min[last];
			for (int j = last; j <= nums[i] + i; j++) {
				if (jump_min[j] < min&&jump_min[j] >= 0) min = jump_min[j];
			}
			jump_min[i] = min + 1;
			last = i;
		}	
	}
	res = jump_min[0];
	free(jump_min);
	return res;
}