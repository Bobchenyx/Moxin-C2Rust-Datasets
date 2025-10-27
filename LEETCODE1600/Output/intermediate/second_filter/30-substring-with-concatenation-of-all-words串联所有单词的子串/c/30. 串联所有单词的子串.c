/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int LastFindFlag(int* flagArr, int wordsSize);
int Find(char* compareStr, int* flagArr, char **words, int wordsSize);
#define FALSE -1
#define TRUE 1

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    *returnSize = 0;
    if (s == NULL || strlen(s) == 0 || words == NULL || wordsSize == 0) {
        return NULL;
    }
    int sLen = strlen(s);
    int wLen = strlen(words[0]);
    int* ret = (int *)malloc(sizeof(int) * sLen);    
    memset(ret, 0, sizeof(int) * sLen);
    int* flagArr = (int*)calloc(sizeof(int), wordsSize);
    char* compareStr = (char*)calloc(sizeof(char), wLen + 1);
    int needFinds = sLen - wLen * wordsSize;
    int retFindflag = FALSE;
    for (int i = 0; i <= needFinds; i++) {
        retFindflag = FALSE;
        for (int j = i; j <= sLen - wLen; j += wLen) {
            strncpy(compareStr, s + j, wLen);    
            retFindflag = Find(compareStr, flagArr, words, wordsSize);
            if (retFindflag == FALSE) {
                break;
            }
        }
        if (LastFindFlag(flagArr, wordsSize) == TRUE) {
            ret[*returnSize] = i;
            *returnSize += 1;
        }
        memset(flagArr, 0, sizeof(int) * wordsSize);
    }
    free(flagArr);
    free(compareStr);
    return ret;
}

int Find(char* compareStr, int* flagArr, char **words, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++) {
        if (flagArr[i] == TRUE) {
            continue;
        }     
        if (strcmp(compareStr, words[i]) == 0) {
            flagArr[i] = TRUE;
            return TRUE;
        }
    }
    return FALSE;
}

int LastFindFlag(int* flagArr, int wordsSize) {
     for (int i = 0; i < wordsSize; i++) {
         if (flagArr[i] != TRUE) {
             return FALSE;
         }
     }
     return TRUE;
}