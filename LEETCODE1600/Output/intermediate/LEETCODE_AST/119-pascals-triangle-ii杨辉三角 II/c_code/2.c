/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    *returnSize = (rowIndex + 1);
    int *arr = (int *)malloc(sizeof(int) * (rowIndex + 1));
    int i, j;

    for (i = 0; i <= rowIndex; i++)
    {
        arr[0] = 1;
        arr[i] = 1;

        for(j = (i - 1); j > 0; j--)
        {
            arr[j] += arr[j - 1];
        }
    }

    return arr;
}