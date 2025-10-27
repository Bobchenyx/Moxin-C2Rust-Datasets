/*
 * Description: 项目 LetterCombinations 的源文件
 * Create: 2019-11-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK  (0)
#define ERR (-1)

char **g_ReturnStrArray = NULL;
unsigned int g_ReturnStrArrayLen = 1;
unsigned int g_CombinationNum = 0;

char g_KeyBoardMap[10][5] = {
    "!@#",    /* 0 */
    "_",    /* 1 */
    "abc", /* 2 */
    "def", /* 3 */
    "ghi", /* 4 */
    "jkl", /* 5 */
    "mno", /* 6 */
    "pqrs",/* 7 */
    "tuv", /* 8 */
    "wxyz",/* 9 */
    ""     /* 10 */
};

void getCombinationString(char *digits, int digitsIndex, char *combinationTempStr)
{
    int i;
    int  KeyValue = digits[digitsIndex] - '0';
    unsigned int tempStrLen = strlen(combinationTempStr);
    
    for(i = 0; i < strlen(g_KeyBoardMap[KeyValue]); i++)
    {
        *(combinationTempStr + tempStrLen) = g_KeyBoardMap[KeyValue][i];
        if(digits[digitsIndex + 1] != '\0')
        {
            getCombinationString(digits, digitsIndex + 1, combinationTempStr);
        }
        else
        {
            memcpy(g_ReturnStrArray[g_CombinationNum], combinationTempStr, strlen(combinationTempStr) + 1);
            g_CombinationNum++;
        }
        
        (void)memset(combinationTempStr + tempStrLen, 0, sizeof(char) * strlen(digits) + 1 - tempStrLen);
        
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * LeetCode答题主函数
 */
char ** letterCombinations(char * digits, int* returnSize){
    int i = 0;
    char *combinationTempStr = NULL;

    if(0 == strlen(digits))
    {
        *returnSize = 0;
        return NULL;
    }
    
    g_CombinationNum = 0;
    g_ReturnStrArrayLen = 1;
    g_ReturnStrArray = NULL;

    combinationTempStr = (char *)malloc(sizeof(char) * strlen(digits) + 1);
    (void)memset(combinationTempStr, 0, sizeof(char) * strlen(digits) + 1);
    
    for(i = 0; i < strlen(digits); i++)
    {
        g_ReturnStrArrayLen *= strlen(g_KeyBoardMap[digits[i] - '0']);
    }
    g_ReturnStrArray = (char **)malloc(sizeof(char *) * g_ReturnStrArrayLen);
    *returnSize = g_ReturnStrArrayLen;
    for(i = 0; i < g_ReturnStrArrayLen; i++)
    {
        g_ReturnStrArray[i] = (char*)malloc(sizeof(char) * strlen(digits) + 1);
        memset(g_ReturnStrArray[i], 0, sizeof(char) * strlen(digits) + 1);
    }
    g_ReturnStrArrayLen *= (sizeof(char) * strlen(digits) + 1);
    getCombinationString(digits, 0, combinationTempStr);
    return g_ReturnStrArray;
}