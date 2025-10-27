int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *l = malloc(sizeof(int) * numsSize);
    int *r = malloc(sizeof(int) * numsSize);
    int *ret = malloc(sizeof(int) * numsSize);
    l[0] = 1;
    r[numsSize - 1] = 1;
    for(int i = 1; i < numsSize; i++){
        l[i] = l[i - 1] * nums[i - 1];
    }
    for(int i = numsSize - 2; i >= 0; i--){
        r[i] = r[i + 1] * nums[i + 1];
    }
    for(int i = 0; i < numsSize; i++){
        ret[i] = l[i] * r[i];
    }
    *returnSize = numsSize;
    return ret;
}