int Comp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int CompHash(void *a, void *b)
{
    int *pa = *(int **)a;
    int *pb = *(int **)b;
    
    return pb[1] - pa[1];
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    /* 总体思路：利用二维数组建立数字和出现次数的映射；key为num
    通过将数据进行排序，则会获取对应的key */
    int *ans = (int *)malloc(sizeof(int) * k);
    int **hash = (int **)calloc(1, sizeof(int *) * numsSize);
    int index = 0;
    int i;
    
    for (i = 0; i < numsSize; i++) {
        hash[i] = (int *)calloc(1, sizeof(int) * 2);
    }
    
    qsort(nums, numsSize, sizeof(int), Comp);
    hash[0][0] = nums[0];
    hash[0][1] = 1;
    index++;
    for (i = 1; i < numsSize; i++) {
        if (hash[index - 1][0] == nums[i]) {
            hash[index - 1][1]++;
        }else {
            hash[index][0] = nums[i];
            hash[index][1] = 1;
            index++;
        }
    }
    
    qsort(hash, numsSize, sizeof(int) * 2, CompHash);
    
    for (i = 0; i < k; i++) {
        ans[i] = hash[i][0];
    }
    
    for (i = 0; i < numsSize; i++) {
        free(hash[i]);
    }
    free(hash);
    *returnSize = k;
    return ans;
}