int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    int j;
    int mod;
    int* a = NULL;
    *returnSize = 2;
    a = (int*)malloc(*returnSize * sizeof(int));

    for (i = 0; i < numsSize; ++i) {
        mod = target - nums[i];
        for (j = 0; j < numsSize; ++j) {
            if (i == j) continue;
            if (mod == nums[j]) break;
        }
        if (j == numsSize) 
            continue;
        else{
            a[0] = i;
            a[1] = j;
            break;
        }
    }

    return a;
}