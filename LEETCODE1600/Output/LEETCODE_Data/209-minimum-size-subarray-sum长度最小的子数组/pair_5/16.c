int minSubArrayLen(int s, int* nums, int numsSize){
    if(numsSize == 0) {
        return 0;
    }
    int i, j, k;
    int sum = 0;
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    memset(temp, 0, sizeof(int) * numsSize);

    for(i = 1; i < numsSize + 1; i++) {
        for(j = 0; j < numsSize + 1 - i; j++) {
            sum = temp[j] + nums[j + i - 1];
            temp[j] = sum;
            if(sum >= s) {
                return i;
            }
        }
    }
    return 0;
}