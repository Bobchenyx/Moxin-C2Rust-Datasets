int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int middle = 0;

    if (nums == NULL) {
        return 0;
    }
    if (nums[0] > target) {
        return 0;
    }
    if (nums[numsSize - 1] < target) {
        return numsSize;
    }

    while (left < right) {
        middle = left + (right - left) / 2;
        //printf("left: %d, right: %d,middle: %d\n",left, right, middle);
        if (nums[middle] == target) {
            return middle;
        }
        if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    return left;
}