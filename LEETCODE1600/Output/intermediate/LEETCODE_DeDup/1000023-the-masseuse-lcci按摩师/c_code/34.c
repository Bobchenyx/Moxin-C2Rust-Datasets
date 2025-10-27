int massage(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    else if (numsSize == 1) return *nums;
    else if (numsSize == 2) return nums[0] > nums[1] ? nums[0] : nums[1];

    int k1 = nums[0], k2;
    int t1 = massage(nums + 2, numsSize - 2), t2 = massage(nums + 3, numsSize - 3);
    k1 += t1 > t2 ? t1 : t2;
    k2 = massage(nums + 1, numsSize - 1);
    return k1 > k2 ? k1 : k2;

}