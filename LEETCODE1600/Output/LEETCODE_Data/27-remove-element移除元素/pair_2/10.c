int removeElement(int* nums, int numsSize, int val){
	if(numsSize<1) {
		return numsSize;
	}
	int k=0;
	for(int i=0;i<numsSize;i++) {
		if(nums[i]==val) {
			k++;
		} else {
			nums[i-k]=nums[i];
		}
	}
	return numsSize-k;
}