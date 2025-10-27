char * longestCommonPrefix(char ** strs, int strsSize) {
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];
    int j = 0, i;
    for(; strs[0][j] != '\0'; j++) {
        for(i = 1; i < strsSize && strs[i][j] != '\0'; i++) {
            if (strs[i][j] != strs[0][j]) break;
        }
        if (i < strsSize)
        {
            strs[0][j] = '\0';
            break;
        }
    }
    return strs[0];

}