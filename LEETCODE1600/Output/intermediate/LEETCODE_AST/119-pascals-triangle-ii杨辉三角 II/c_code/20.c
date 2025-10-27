int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int* p = (int*)malloc(sizeof(int) * (rowIndex + 1));
    int i, j, k = 0;
    for(i = 0; i <= rowIndex; i++){
        p[k++] = 1;
        for(j = i - 1; j >= 1; j--){
            p[j] += p[j-1];
        }
    }
    return p;
}