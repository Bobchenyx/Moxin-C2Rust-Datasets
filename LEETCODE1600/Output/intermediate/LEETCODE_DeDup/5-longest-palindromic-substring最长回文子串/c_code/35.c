#include <string.h>
#include <stdlib.h>
#define MAX_N 2000

// 寻找最长回文子串
void palindrome(char* dest, const char* s, int left, int right)
{
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    
    strncpy(dest, s + left + 1, right - 1 - left);
    return;  
}

char * longestPalindrome(char * s)
{
    if (s == NULL || strlen(s) <= 1) {
        return s;
    }
    
    int len = strlen(s);
    int i;
    char* res = (char*)malloc(MAX_N * sizeof(char));  // 这个一定要用malloc申请
    memset(res, 0, MAX_N * sizeof(char));
    
    for (i = 0; i < len; i++) {
        char s1[MAX_N] = {0};   // 一定要用数组
        char s2[MAX_N] = {0};   // 一定要用数组
        palindrome(s1, s, i, i);     // 以s[i]为中心的最长回文子串
        palindrome(s2, s, i, i + 1);    // 以s[i]和s[i+1]为中心的最长回文子串
        
        // 返回res, s1, s2中最大者
        if (strlen(s1) > strlen(res)) {
            strcpy(res, s1);    // 如果res不够大，复制字符串时会发生溢出
        }
        
        if (strlen(s2) > strlen(res)) {
            strcpy(res, s2);    // 如果res不够大，复制字符串时会发生溢出
        }
    }
    
    return res;
}