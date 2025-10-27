int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0) return 0;
	int slow=0,fast;
	for(fast=1;fast<numsSize;fast++){
		if(nums[fast]!=nums[slow]){
			nums[++slow]=nums[fast];
		}		
	}
	return slow+1;
}