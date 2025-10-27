int findRepeatNumber(int* nums, int numsSize){
    int *countArr = (int*)malloc(sizeof(int)*numsSize);
    int repeat = -1;
    memset(countArr, 0, numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        countArr[nums[i]]++;
        if (countArr[nums[i]] > 1) {
            repeat = nums[i];
            break;
        }
    }
    return repeat;
}