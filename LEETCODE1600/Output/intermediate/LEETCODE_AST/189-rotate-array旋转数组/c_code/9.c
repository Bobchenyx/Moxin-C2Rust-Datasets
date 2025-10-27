void reverse(int* nums,int start,int end){
	int temp;
	while(start<end){
		temp=nums[start];
		nums[start++]=nums[end];
		nums[end--]=temp;
	}
}
void rotate(int* nums, int numsSize, int k){
	reverse(nums,0,numsSize-1);
	reverse(nums,0,k%numsSize-1);
	reverse(nums,k%numsSize,numsSize-1);
}