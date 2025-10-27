#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize){
    // 利用前缀和
    int i;
    int sum = 0;
    int max = 0;
    int temp = -100;

    if (numsSize == 0) {
        return 0;
    }

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum <= 0) {
            if (nums[i] <= 0) {
                temp = MAX(temp, nums[i]);
            }

            sum = 0;
            continue;
        }

        max = MAX(max, sum);
    }

    if (max == 0) {
        return temp;
    }

    return max;
}