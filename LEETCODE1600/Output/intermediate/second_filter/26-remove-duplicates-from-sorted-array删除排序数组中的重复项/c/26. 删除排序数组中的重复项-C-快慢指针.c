int removeDuplicates(int* nums, int numsSize){
    if(nums == NULL || numsSize == 0) {
        return 0;
    }

    int slow = 0;
    int fast = 1;

    while (fast < numsSize) {
        if (nums[fast] == nums[slow]) {
            fast++;
        }else {
            nums[++slow] = nums[fast];
        }
    }

    return slow + 1;
}