int* getRow(int rowIndex, int* returnSize){
    int* ret = calloc(rowIndex + 1, sizeof(int));
    ret[0] = 1;
    for (int i = 0; i <= rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            ret[j] = ret[j] + ret[j - 1];
        }
    }
    
    *returnSize = rowIndex + 1;
    return ret;
}