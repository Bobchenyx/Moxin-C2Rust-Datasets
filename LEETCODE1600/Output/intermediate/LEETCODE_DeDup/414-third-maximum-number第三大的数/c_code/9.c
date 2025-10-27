int cmpf(const void *a, const void *b) {
    return (*(int *)b) > (*(int *)a);
}

int thirdMax(int* nums, int numsSize){
    int i;
    int ii = 0;
    int count = 0;
    int temp;
    if (numsSize == 1) {
        return nums[0];
    }
    if (numsSize == 2) {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }

    // printf("qsort before:\n");
    qsort(nums, numsSize, sizeof(int), cmpf);
    // printf("qsort after:\n");
    for (i = 1, temp = nums[0]; i < numsSize; i++) {
        if (temp > nums[i]) {
            count++;
            if (count == 2) {
                ii = i;
                // printf("ii = %d\n",ii);
                break;
            }
        }
        temp = nums[i];
    }

    if (count < 2) {
        ii = 0;
    }
    return nums[ii];
}