/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #define SIZE 500
 #define CHR_NUM 26

 int max(int a, int b)
 {
     return a > b ? a : b;
 }

int* partitionLabels(char * S, int* returnSize){
    if (S == NULL) {
        return NULL;
    }

    int *retList = (int *)calloc(sizeof(int), SIZE);
    int retCnt = 0;
    int positionList[CHR_NUM] = {0};

    for (int i = 0; i < strlen(S); i++) {
        positionList[S[i] - 'a'] = i;
    }

    int maxLast = 0;
    int num = 0;

    for (int i = 0; i < strlen(S); i++) {
        maxLast = max(maxLast, positionList[S[i] - 'a']);
        num++;
        if (maxLast == i) {
            retList[retCnt] = num;
            retCnt++;
            num = 0;
        }
    }

    *returnSize = retCnt;
    return retList;
}