/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSize)
{
    *returnSize = numRows;
    int** res = (int**)malloc(sizeof(int*) * numRows);
    *returnColumnSize = (int*)malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++)
    {
        (*returnColumnSize)[i] = i + 1;
        res[i] = (int*)malloc(sizeof(int) * (i + 1));
        res[i][0] = 1;
        res[i][i] = 1;
    }
    for (int i = 2; i < numRows; i++)
    {
        for (int j = 1; j < i; j++)
        {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}