/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int xor;    
    int *prefixXor = (int *)malloc(sizeof(int) * arrSize);
    memset(prefixXor, 0, sizeof(int) * arrSize);

    int *retArr = (int *)malloc(sizeof(int) * queriesSize);
    memset(retArr, 0, sizeof(int) * queriesSize);

    prefixXor[0] = arr[0];
    for (int i = 1; i < arrSize; i++) {
        prefixXor[i] = prefixXor[i - 1] ^ arr[i];
    }

    for (int i = 0; i < queriesSize; i++) {
        /* XOR[0, Ri] xor XOR[0, Li-1] = XOR[Li, Ri] */
        retArr[i] = prefixXor[queries[i][1]] ^ ((queries[i][0] != 0) ? prefixXor[queries[i][0] - 1] : 0);
    }
    
    free(prefixXor);

    *returnSize = queriesSize;
    return retArr;
}