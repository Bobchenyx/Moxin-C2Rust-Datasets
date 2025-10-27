char * longestCommonPrefix(char ** strs, int strsSize)
{
    if(!strsSize)               /* 空字符串，返回"" */
        return "";

    char *s = *strs;            /* 以第一个字符串为参照 */
    for(int i = 1, j; i < strsSize; ++i) {
        for(j = 0; *(s+j) && *(*(strs+i)+j) && *(s+j) == *(*(strs+i)+j); ++j)   /* 寻找不相同字符的位置 */
            ;
        *(s+j) = '\0';          /* 截断字符串 */
    }
    return s;
}