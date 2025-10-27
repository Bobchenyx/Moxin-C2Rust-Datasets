int removeDuplicates(int* nums, int numsSize){
    int i = 0;
    if(nums == NULL || numsSize == 0){
        return 0;
    }

    for(int j = 1; j < numsSize; ++j){
        if(nums[j] != nums[i]){
            nums[++i] = nums[j];
        }
    }
    return i+1;
}