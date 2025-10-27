/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX 21
//#define ABS(n) (n) < 0 ? (-(n)) : (n)
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    int array = 0;
    int i, j;
    int sum = *AColSize - 1;
    for (i = 0; i < ASize; i++) {
        for (j = 0; j < (*AColSize + 1)/2; j++) {
            array = A[i][j];
            A[i][j] = A[i][sum - j];
            A[i][sum - j] = array;
        }
    }
    for (i = 0; i < ASize; i++) {
        for (j = 0; j < *AColSize; j++) {
            A[i][j] = abs(A[i][j] - 1);
        }
    }
    * returnSize = ASize;
    * returnColumnSizes = AColSize;

    return A;

}