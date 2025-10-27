int* findErrorNums(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int hash[numsSize + 1];
    memset(hash, 0,sizeof(int) * (numsSize + 1));
    int *answer = malloc(sizeof(int) * 2);
    memset(answer, 0, sizeof(int) * 2);

    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]]++;
    }
    for (int i = 0; i < numsSize; i++) {
        if (hash[nums[i]] == 2) {
            answer[0] = nums[i];
        }
    }
    for (int i = 1; i < numsSize + 1; i++) {
        if (hash[i] == 0) {
            answer[1] = i;
        }
    }
    return answer;
}