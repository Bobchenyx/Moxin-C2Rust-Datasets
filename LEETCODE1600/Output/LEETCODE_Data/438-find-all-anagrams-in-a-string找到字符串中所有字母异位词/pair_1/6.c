/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_STRING_LEN 20100
int* findAnagrams(char * s, char * p, int* returnSize){
    if (s == NULL || p == NULL || returnSize == NULL) {
        return NULL;
    }

    *returnSize = 0;
    int dict[26] = {0};
    int loop = 0;
    int pLen = strlen(p);
    int begin = 0; 
    int end = 0; /* 滑窗的开头和结尾 */
    int *result = (int *)malloc(sizeof(int) * MAX_STRING_LEN);
    if (result == NULL) {
        return NULL;
    }

    (void)memset(result, 0, sizeof(int) * MAX_STRING_LEN);
    /* 统计出目标字符串组各元素个数 */
    for (; loop < pLen; loop++) {
        dict[p[loop] - 'a']++;
    }

    for (; end < strlen(s); end++) {
        dict[s[end] - 'a']--;

        while (dict[s[end] - 'a'] < 0) {
            dict[s[begin] - 'a']++;
            begin++;
        }

        if (pLen == end - begin + 1) {
            result[*returnSize] = begin;
            (*returnSize)++;

            dict[s[begin] - 'a']++;
            begin = begin + 1;
        }
    }

    return result;
}