#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))
int proc(int *nums, int numsSize)
{
	int i;
	int max;
	int dp0, dp1, dp2;
	dp0 = nums[0];
	dp1 = nums[1];
	max = dp0;
	for (i = 2; i < numsSize; i++) {
		dp2 = MY_MAX(dp1, max + nums[i]);
		max = MY_MAX(max, dp1);
		dp0 = dp1;
		dp1 = dp2;
	}
	return dp2;
}
int massage(int* nums, int numsSize){
    if (numsSize <= 0 || nums == NULL) {
		return 0;
	}
	if (numsSize == 1) {
		return nums[0];
	}
	if (numsSize == 2) {
		return MY_MAX(nums[0], nums[1]);
	}
	return proc(nums, numsSize);
}