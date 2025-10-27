int dominantIndex(int* nums, int numsSize){
    int i, max, second = 0, index = 0;

    max = nums[0];

    for (i = 1; i < numsSize; i++) {
        if (max < nums[i]) {
            second = max > second ? max : second;
            max = nums[i];
            index = i;
        } else if (nums[i] > second){
            second = nums[i];
        }
    }
    if (max >= second * 2)
        return index;
    else
        return -1;
}