int maxSubArray(int* nums, int numsSize){
    int i;
    int isAllMinus = 1;
    int maxNum = -100000000;
    int start, end;
    int sum = 0;

    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            isAllMinus = 0;
            break;
        }
    }

    if (isAllMinus == 1) {
        for (i = 0; i < numsSize; i++) {
            maxNum = (maxNum > nums[i]) ? maxNum : nums[i];
        }
        return maxNum;
    }

    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            start = i;
            break;
        }
    }
    printf("start = %d", start);
    if (numsSize - 1 == start) {
        printf("a");
        return nums[start];
    }
    
    end = start;
    sum = 0;
    while (end < numsSize) {
        sum += nums[end];
        if (sum > maxNum) {
            printf("%d", sum);
            maxNum = sum;
        } else if (sum <= 0) {
            start = end;
            sum = 0;
        }
        end++;
    }
    return maxNum;
}