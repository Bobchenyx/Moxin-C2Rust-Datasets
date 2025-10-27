C []
void rotate(int* nums, int numsSize, int k){
	int i = 0;
	int tmp = 0;
	int j = 0;
    k %= numsSize;//只需要旋转小于numsSize的长度
	for (i = 0, j = numsSize - 1 - k; i<j; i++, j--)//对前半部分逆置
    {
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (i = numsSize - k, j = numsSize - 1; i<j; i++, j--)//对后半部分逆置
    {
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (i = 0, j = numsSize-1; i<j; i++, j--)//对整体数组逆置
    {
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}

}