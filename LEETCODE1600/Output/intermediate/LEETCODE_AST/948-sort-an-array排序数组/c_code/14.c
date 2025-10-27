/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if (numsSize < 2)
        return nums;
    int min = nums[0], max = nums[0], i = 0, j = 0;
    for (; i < numsSize; ++i){
        min = min < nums[i] ? min : nums[i];
        max = max > nums[i] ? max : nums[i];
    }
    int value = max - min + 1;
    int result[value];
    for (i = 0; i < value; ++i)
        result[i] = 0;
    for (i = 0; i < numsSize; ++i)
        ++result[nums[i] - min];
    for (i = 0; i < value; ++i)
        while (result[i]--)
            nums[j++] = i + min;
    return nums;
}