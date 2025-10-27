int removeElement(int* nums, int numsSize, int val){
    if (numsSize <= 0) return numsSize;
    int current = 0;
    for (int slide = 0; slide < numsSize; slide++) {
        if (nums[slide] != val) {
            nums[current++] = nums[slide];
        }
    }
    return current;
}