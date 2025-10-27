#include<stdio.h>
int removeDuplicates(int* nums, int numsSize){
	int i,j,k;
	for(i = 0; i < numsSize-1; i ++){
		for(j = i + 1; j < numsSize;){
			if(nums[i] == nums[j]){
				for(k = j; k < numsSize -1; k ++){
					nums[k]=nums[k+1];
				}
				numsSize --;
			}
		    else j ++;
		}
	}
	return numsSize;
}