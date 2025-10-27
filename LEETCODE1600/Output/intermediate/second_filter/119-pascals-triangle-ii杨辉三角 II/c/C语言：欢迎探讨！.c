int* getRow(int rowIndex, int* returnSize){
    static int yangtri[34][34];//不加static的话，会出现**错误提示：**load of null pointer of type 'const int'
    *returnSize = rowIndex + 1;
    int i, j;
    for (i = 0; i <= rowIndex; i++)
        yangtri[i][0] = 1;
    for (i = 1; i <= rowIndex; i++)
        yangtri[i][i] = 1;
    for (i = 2; i <= rowIndex; i++){
        for (j = 1; j < rowIndex; j++){
            yangtri[i][j] = yangtri[i - 1][j - 1] + yangtri[i - 1][j];
        }
    }
    return yangtri[rowIndex];
}