int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    * returnSize = numsSize;
    int *pos = malloc(sizeof(int) * numsSize);
    int *res = malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(pos[j] >= index[i])
                pos[j]++;
        }
        pos[i] = index[i];
    }
    for(int i = 0; i < numsSize; i++)
    {
        res[pos[i]] = nums[i];   
    }
    return res;
}