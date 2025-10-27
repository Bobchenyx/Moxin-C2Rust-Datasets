/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){

    *returnSize = rowIndex + 1;

    int *res = (int *)malloc( sizeof(int) * (rowIndex + 1));
    //初始化都为1
    for (int i = 0; i < rowIndex+1; i++) res[i] = 1;

    for (int i = 1; i < rowIndex; i++){
        for(int j = i; j >=0 ; j--){
            if (j == 0 || j == (rowIndex + 1)) {
                res[j] = 1;
            } else{
                res[j] = res[j-1] + res[j];
            }

        }
    }
    return res;

}