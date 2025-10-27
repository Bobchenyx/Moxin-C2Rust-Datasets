/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    if (arrSize == 0 || queriesSize == 0) {
        return NULL;
    }
    int pri[arrSize + 1];
    int *ans = (int *)malloc(sizeof(int) *queriesSize); 
    pri[0] = arr[0];
    for (int i = 1; i < arrSize; i++) {
        pri[i] = pri[i - 1] ^ arr[i];
        // printf("pri[%d]:%d\n",  i, pri[i]);
    }
    for (int i = 0; i < queriesSize; i++) {
        int begin = queries[i][0];
        int end = queries[i][1];
        if (begin != end) {
            if (begin == 0) {
                ans[i] = pri[end];
            } else {
                ans[i] = pri[begin - 1] ^ pri[end];
            }
            
        } else {
            ans[i] = arr[end];
        } 
        // printf("[%d]:%d\n",  i, ans[i]);
    }
    *returnSize = queriesSize;
    return ans;
}