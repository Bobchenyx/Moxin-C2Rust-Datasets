int majorityElement(int* nums, int numsSize){
    int s = 1;
	int maj = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (maj == nums[i]){
			s++;
		}
		else {
			s--;
			
		}
		if (s == 0) {
			maj = nums[i + 1];
		}
	}
	return maj;

}