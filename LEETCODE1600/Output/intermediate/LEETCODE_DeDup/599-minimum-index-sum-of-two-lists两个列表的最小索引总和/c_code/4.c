/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MIN(a, b) (a < b ? a : b)
#define PER_STRING_LEN  30
#define MAX_INDEX  2000

char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    int currMinIndex = 0;
    int preMinIndex = MAX_INDEX;
    char **returnList = (char**)malloc((list1Size + 1) * sizeof(char*));
    for (int k = 0; k < list1Size; k++) {
        returnList[k] = (char*)malloc((PER_STRING_LEN + 1) * sizeof(char));
    }
    *returnSize = 0;

    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {
            if (strcmp(list1[i], list2[j]) == 0) {
                currMinIndex = i + j;
                if (currMinIndex <= preMinIndex) {
                    returnList[*returnSize] = list1[i];
                    (*returnSize)++;
                    preMinIndex = currMinIndex;
                    break;
                }
            }
        }
    }

    return returnList;
}