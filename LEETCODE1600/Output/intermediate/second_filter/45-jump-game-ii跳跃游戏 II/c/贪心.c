int jump(int* nums, int numsSize)
{
    if (numsSize <= 1) return 0;
    for (int i = 0; i < numsSize; i++) {
        nums[i] += i;
    }
    int ret = 1;
    int leftStep = nums[0];
    int maxStep = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (leftStep < i) {
            ret++;
            leftStep = maxStep;
        }
        if (nums[i] > maxStep) {
            maxStep = nums[i];
        }
    }
    return ret;
}