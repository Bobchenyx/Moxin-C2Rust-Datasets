double findMaxAverage(int* nums, int numsSize, int k){
    //先计算sums数组
    double maxAve = -10000;
    double tmpAve = 0;
    int* sums = (int*)malloc(sizeof(int) * numsSize);
    memset(sums, 0, sizeof(int) * numsSize);
    if (numsSize == 1) {
        return *nums;
    }
    *sums = *nums;
    for(int i = 1;i < numsSize; i++) {
        *(sums + i) =  *(sums + i -1) + *(nums + i);
    }
    if (k == numsSize) {
        maxAve = (double)(*(sums + numsSize - 1))/k;
    }
    for (int j = 0; j <= numsSize - k; j++) {
        if (j == 0) {
            tmpAve = (double)(*(sums + k - 1))/k;
        } else {
            tmpAve = (double)(*(sums + j + k - 1) - *(sums + j -1))/k;
        }
        if (maxAve < tmpAve) {
            maxAve = tmpAve;
        }
        
    }
    free(sums);
    return maxAve;
}