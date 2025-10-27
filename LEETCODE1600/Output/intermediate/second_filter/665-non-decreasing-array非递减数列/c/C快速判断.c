bool checkPoss(int* nums, int numsSize, int delInx){
	int i;
	int cnt = 0;
	int last = INT_MIN;
	for (i = 0; i < numsSize; i++) {
		if (i == delInx) {
			continue;
		}
		if (nums[i] < last) {
			cnt++;
		}
		last = nums[i];
	}
	if (cnt > 0) {
		return false;
	}
	return true;
}
bool checkPossibility(int* nums, int numsSize){
	int i;
	int cnt = 0;
	int last = INT_MIN;
	int d1, d2;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] < last) {
			cnt++;
			d1 = i - 1;
			d2 = i;
		}
		last = nums[i];
	}
    /* 一直没有减小，所以OK */
    if (cnt == 0) {
		return true;
	}
    /* 如果有两次减小，一定不符合 */
	if (cnt > 1) {
		return false;
	}
    /* 如果只有一次减小，逐次去掉下降点的点，如果不再下降则OK */
	return checkPoss(nums, numsSize, d1) || checkPoss(nums, numsSize, d2);
}