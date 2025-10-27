static int Compare(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

static int GetLeft(int* nums, int numsSize)
{
    int left = numsSize - 2;
    while (left >= 0) {
        if (nums[left] < nums[left + 1]) {
            break;
        }
        left--;
    }
    return left;
}

static int GetRight(int* nums, int numsSize, int left)
{
    int right;
    for (right = left + 1; right < numsSize; right++) {
        if (nums[left] >= nums[right]) {
            break;
        }
    }
    return right - 1;
}

static void swapNum(int* nums, int left, int right)
{
    int tmp = nums[left];
    nums[left] = nums[right];
    nums[right] = tmp;
}

void nextPermutation(int* nums, int numsSize)
{
    if ((numsSize == 0 || (nums == NULL))) {
        return;
    }
    int left = GetLeft(nums, numsSize);
    if (left == -1) {
        qsort(nums, numsSize, sizeof(int), Compare);
        return;
    }
    int right = GetRight(nums, numsSize, left);
    swapNum(nums, left, right);
    qsort(nums + left + 1, numsSize - left - 1, sizeof(int), Compare);
}