int firstMissingPositive(int* nums, int numsSize)
{
    int minPos = 1;
    int lastGreatPos = -1;
    for (int i = 0; i < numsSize; i++) {
        int curVal = nums[i];
        if (curVal < minPos) {
            if (lastGreatPos > 0) {
                nums[i] = nums[lastGreatPos];
                lastGreatPos++;
                if (lastGreatPos > numsSize) {
                    break;
                }
            }
        }
        else if (curVal > minPos) {
            if (lastGreatPos < 0) {
                lastGreatPos = i;
            }
        }
        if (minPos == curVal) {
            minPos++;
            if (lastGreatPos > 0) {
                nums[i] = nums[lastGreatPos];
                i = lastGreatPos;
                lastGreatPos++;
                if (lastGreatPos > numsSize) {
                    break;
                }
            } else {
                i = -1;
            }
        }
    }
    return minPos;
}