int removeElement(int* nums, int numsSize, int val){
    int i, j;
    int len = 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            len++;
        }
    }

    for (i = 0, j = numsSize - 1; i < len;) {
        if (nums[i] == val) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
                j--;
            }
            else {
                j--;
            }
        } else {
            i++;
        }
    }

    return len;
}