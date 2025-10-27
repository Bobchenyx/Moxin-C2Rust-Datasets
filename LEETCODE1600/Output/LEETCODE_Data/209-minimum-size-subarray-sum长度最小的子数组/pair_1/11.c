//滑动窗口

int minSubArrayLen(int s, int* nums, int numsSize)
{
    int start = 0;
    int end = 0;
    int returnVal = 0x7fffffff;
    int tmpS = 0;

    while (end < numsSize) {
        while ((tmpS < s) && (end < numsSize)) {
            tmpS = tmpS + nums[end];
            end++;
            if (tmpS >= s) {
                if (returnVal > (end - start)) {
                    returnVal = end - start;
                }
            }
        }
        if (tmpS >= s) {
            if (returnVal > (end - start)) {
                returnVal = end - start;
            }
        }
        //printf("start: %d, end %d, tmpS: %d\n", start, end, tmpS);
        tmpS = tmpS - nums[start];
        start++;
    }
    //printf("numsSize: %d\n", numsSize);
    while (start < end) {
        if ((tmpS >= s) && (end == numsSize)) {
            if (returnVal > (end - start)) {
                returnVal = end - start;
            }
        }
        //printf("start: %d, end %d, tmpS: %d\n", start, end, tmpS);
        tmpS = tmpS - nums[start];
        start++;
    }
    if (returnVal == 0x7fffffff) {
        return 0;
    } else {
        return returnVal;
    }
}