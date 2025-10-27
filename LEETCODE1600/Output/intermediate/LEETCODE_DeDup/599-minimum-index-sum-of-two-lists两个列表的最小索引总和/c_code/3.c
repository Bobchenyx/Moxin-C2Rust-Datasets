/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXS 10240
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    int i, j, idxSum, limitJ;
    char **pRes = NULL;
    int record[MAXS] = { 0 };
    limitJ = list2Size;
    idxSum = MAXS;
    *returnSize = 0;
    for (i = 0; i < list1Size; i++) {
        for (j = 0; j < limitJ; j++) {
            if (strcmp(list1[i], list2[j]) == 0) {
                if (idxSum > i + j) {
                    idxSum = i + j;
                    limitJ = j;
                    record[0] = j;
                    *returnSize = 1;
                    break;
                } else if (idxSum == i + j) {
                    limitJ = j;
                    record[*returnSize] = j;
                    (*returnSize)++;
                    break;
                } else {
                    break;
                }
            }
        }
    }

    pRes = (char **)malloc(sizeof(char *) * (*returnSize));
    for (i = 0; i < *returnSize; i++) {
        pRes[i] = (char *)malloc(sizeof(char) * (strlen(list2[record[i]]) + 1));
        memcpy(pRes[i], list2[record[i]], sizeof(char) * strlen(list2[record[i]]));
        pRes[i][strlen(list2[record[i]])] = '\0';
    }
    return pRes;
}