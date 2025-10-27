int singleNumber(int* nums, int numsSize)
{

	int k = nums[0];
	int i;
	for( i = 1; i < numsSize; i++ ){
		k = k ^ nums[i];
	}
	return k;
}