int *Max(int *num, int size){
    int *tmp = num;
    if (size == 1)
        return tmp;

    for (int k = 1; k < size; k++) {
        if (*(num + k) >= *tmp) {
            tmp = num + k;        
        }
    }
    return tmp;
}

int jump(int* nums, int numsSize){
    int *h = nums;
    int *t = NULL;
    int i = 0; 

    if (numsSize <= 1)
        return 0;

    int index[numsSize];
    for (int i = 0; i < numsSize; i++) {
        index[i] = nums[i] + i;
    }

    int *h1 = index;
    int *t1 = NULL;

    while(1) {
        i++;
        if ((*h + (h - nums) + 1) >= numsSize) { 
            break;
        }
        t1 = Max((h1 + 1), *h);
        h = h + (t1 - h1);
        h1 = t1;
    }

    return i;
}