int* getRow(int rowIndex, int* returnSize){
    int i, j;
    int numsSize = rowIndex + 1;
    int rowSize = 0;
    int rowStartIdx = 0;
    int* rowNums = NULL;

    if (rowIndex< 0 || returnSize == NULL) {
        *returnSize = 0;
        return NULL;
    }

    rowNums = (int*)calloc(numsSize, sizeof(int));
    rowNums[rowIndex] = 1;

    for (i = 0; i <= rowIndex; i++) {
        rowSize = i + 1;
        rowStartIdx = rowIndex - i;
        rowNums[rowStartIdx] = 1;
        for (j = rowStartIdx + 1; j < rowIndex; j++) {
            rowNums[j] = rowNums[j] + rowNums[j + 1];
        }
    }

    *returnSize = numsSize;

    return rowNums;
}