int _compare_int(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

void getNextArray(int *nums, int numsSize) {
    int heightIdx = -1;
    int lowIdx = -1;
    for (int i = numsSize - 1; i >= 0; --i) {
        //找到高位比低位小的，交换位置，得到一个更大的值
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] < nums[i]) {
                //注意，最后选择一个值最小的高位来交换，这样才是最接近的
                if (heightIdx == -1 || j > heightIdx) {
                    heightIdx = j;
                    lowIdx = i;
                }
            }
        }
    }
    if (heightIdx == -1) {
        printf("error\n");
        return;
    }

    //进行高低位值交换
    int temp = nums[lowIdx];
    nums[lowIdx] = nums[heightIdx];
    nums[heightIdx] = temp;

    //对高位后面的值，进行从小到大排序，保证是最小的值
    qsort(&nums[heightIdx + 1], numsSize - heightIdx - 1, sizeof(int), _compare_int);
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (numsSize == 0) {
        return NULL;
    }

    //计算总排列个数，即N!
    int size = 1;
    for (int i = 1; i <= numsSize; i++) {
        size *= i;
    }

    //分配返回值的内存空间
    int **retVal = malloc(sizeof(int *) * size);
    *returnColumnSizes = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        (*returnColumnSizes)[i] = numsSize;
        retVal[i] = malloc(sizeof(int) * numsSize);
    }

    //对原数组从小到大排序，得到最小排列
    qsort(nums, numsSize, sizeof(int), _compare_int);
    
    //一个接着一个，获取下一个最接近的排列
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < numsSize; ++j) {
            retVal[i][j] = nums[j];
        }
        getNextArray(nums, numsSize);
    }
    *returnSize = size;
    return retVal;
}