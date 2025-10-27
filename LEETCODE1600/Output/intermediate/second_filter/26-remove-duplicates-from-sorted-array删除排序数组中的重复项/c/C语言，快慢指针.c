int removeDuplicates(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int fast = 1;
    int slow = 0;
    while (fast < numsSize) {
        if (nums[slow] != nums[fast]) {
            nums[++slow] = nums[fast++];
        }else {
            fast++;
        }
    }
    return (slow + 1);
}