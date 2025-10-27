int removeElement(int* nums, int numsSize, int val){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int slow = 0;
    int fast = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[fast] == val) {
            fast++;
        }else {
            nums[slow++] = nums[fast++];
        }
    }

    return slow;
}