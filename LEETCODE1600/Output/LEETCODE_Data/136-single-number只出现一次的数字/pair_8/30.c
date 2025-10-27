//暴力破解法
int singleNumber(int* nums, int numsSize){
	if( numsSize <= 1 ){
		return nums[0];
	}
	int i,j;
	int symbol = 0;
	for( i = 0; i < numsSize; ++i ){
		symbol = 0;
		for( j = 0; j < numsSize; ++j ){
			if( i == j ){
				continue;
			}
			if( nums[i] == nums[j] ){
				symbol = 1;
				break;
			}
		}
		if( symbol == 1 ){
			continue;
		}else{
			break;
		}
	}
	return nums[i];
}