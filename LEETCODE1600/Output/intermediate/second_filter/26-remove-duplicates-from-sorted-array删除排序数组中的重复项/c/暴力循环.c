int removeDuplicates(int* nums,int numsSize){
    if(numsSize<=1) return numsSize;
	int i=0,count=1;
	for(i=0;i<numsSize-1;i++){
		if(nums[i]!=nums[i+1]){
			nums[count]=nums[i+1];
			count++;
		}
	}
	return count;
}