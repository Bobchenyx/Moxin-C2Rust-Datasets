int removeDuplicates(int* nums, int numsSize){
	int i, j=1;
    if (numsSize == 0) j=0;
    for(i=0;i<numsSize-1;i++) {
    	if (nums[i] != nums[i+1]) {
    		nums[j] = nums[i+1];
    		j++;
		}
	}
	return j;
}