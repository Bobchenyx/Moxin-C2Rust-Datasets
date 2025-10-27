int searchInsert(int* nums, int numsSize, int target){
	if(numsSize<1) {
		return 0;
	}
	
	for(int i=0; i<numsSize; i++) {
		if(nums[i]>=target) {
			return i;
		}
	}
	return numsSize;
}