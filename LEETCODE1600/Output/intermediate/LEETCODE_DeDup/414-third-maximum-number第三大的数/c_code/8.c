int cmp(const void *a, const void *b)
{
	return *(int*)a < *(int*)b; 
}
int thirdMax(int* nums, int numsSize){
	int i, j;
	int last;
	qsort(nums, numsSize, sizeof(int), cmp);
	last = nums[0];
	for (i = 1, j = 1; i < numsSize; i++) {
		if (last == nums[i]) {
			continue;
		}
		last = nums[i];
		nums[j++] = last;
	}
	return j < 3 ? nums[0] : nums[2];
}