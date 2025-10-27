#include <string.h>
#define N 100000 
char * longestCommonPrefix(char ** strs, int strsSize)
{
    // 处理空字符串
    if (strs == NULL || strsSize < 1) {
        return "";
    }
    // 只有一个字符串，直接返回
    if (strsSize == 1) {
        return strs[0];
    }

    char* common = (char*)malloc(N * sizeof(char));
    memset(common, 0, N * sizeof(char));

    int i;  // 行指针，遍历每个字符串
    int j; // 列指针，遍历单个字符串的每个字符
    int k = 0;  // common指针
    int columnLen = strlen(strs[0]);
    
    for (j = 0; j < columnLen; j++) {
        for (i = 1; i < strsSize; i++) {
            if (strs[i][j] != strs[0][j]) {
                return common;
            }
        }
        // 将公有字符加到common中
        common[k++] = strs[0][j];
    }
    
    common[k] = '\0';

    return common;
}