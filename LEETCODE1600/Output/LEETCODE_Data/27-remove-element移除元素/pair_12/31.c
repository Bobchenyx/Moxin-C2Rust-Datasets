if (numsSize == 0) {
        return 0;
    }
    int index = 0;
    for (int i = 1; i < numsSize; i++) {
        if (*(nums+i) != val) {
            index++;
            nums[index] = nums[i];
        }
    }
    return index;
}