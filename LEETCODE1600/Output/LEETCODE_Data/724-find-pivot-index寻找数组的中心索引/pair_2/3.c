int pivotIndex(int* nums, int numsSize){
    int left  = 0;
    int right = 0;
    int index;
    
    if (numsSize < 3) {
        return -1;
    }
    
    for (index = 1; index < numsSize; index++) {
        right = right + nums[index];
    }
    
    if (right == 0) {
        return 0;
    }
    
    for (index = 1; index < numsSize - 1; index++) {
        left = left + nums[index - 1];
        right = right - nums[index];
        if (left == right) {
            return index;
        }
    }

    if (left + nums[index - 1] == 0) {
        return index;
    }
    
    return -1;
}