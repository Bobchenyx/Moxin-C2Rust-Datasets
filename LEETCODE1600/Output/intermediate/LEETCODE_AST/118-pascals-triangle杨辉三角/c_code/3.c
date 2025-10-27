/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;//returnSize是真相一个整数的指针，表示返回杨辉三角的行数 = 输入numRows
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));//returnColumnSizes是指向一个数组的指针，数组元素为对应行的元素个数
    int **res = (int**)malloc((*returnSize) * sizeof(int*));//res是一个指针，它指向的是由指针构成的数组，每个指针都指向对应的三角的一行数；res也是二维数组
    int i = 0;
    for(; i < *returnSize; i++){
        (*returnColumnSizes)[i] = i + 1;
        res[i] = (int*)malloc((*returnColumnSizes)[i] * sizeof(int));
        res[i][0] = 1;
        res[i][i] = 1; 
    }
    for(i = 2; i <= numRows - 1; i++){
        for(int j = 1; j < i; j++){
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}