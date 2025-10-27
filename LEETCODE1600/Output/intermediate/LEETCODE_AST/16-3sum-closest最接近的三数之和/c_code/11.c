int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int threeSumClosest(int* nums, int numsSize, int target) {
    int ret, gap = 0x7fffffff;   // gap 记录距离并初始化为最大值，ret 记录此时返回值
    qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < gap) {    //如果距离更短，则更新 gap 和 ret
                gap = abs(sum - target);
                ret = sum;
            }
            if (sum > target) right--;        //移动左右指针
            else if (sum < target) left++;
            else return sum;
        }
    }
    return ret;
}