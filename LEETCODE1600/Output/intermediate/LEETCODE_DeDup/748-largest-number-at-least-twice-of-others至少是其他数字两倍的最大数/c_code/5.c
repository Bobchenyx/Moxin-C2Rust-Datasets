int dominantIndex(int* nums, int numsSize){

    int indexMax = 0;

    for(int i = 0; i < numsSize; i++){

        if(nums[i] > nums[indexMax]){

            indexMax = i;
        }
    }

    for(int i = 0; i < numsSize; i++){

        if(indexMax != i && nums[indexMax] < nums[i] * 2){

            return -1;
        }
    }
    
    return indexMax;
}