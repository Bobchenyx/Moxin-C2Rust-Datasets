char * longestCommonPrefix(char ** strs, int strsSize){
    int strLen = 0;
    char* shortStr = NULL;
    int shortLen = 0;
    int i, j;

    if (strs == NULL || strsSize == 0) {
        return "";
    }
    
    if (strs != NULL && strsSize == 1) {
        return strs[0];
    }

    shortStr = strs[0];
    shortLen = strlen(strs[0]);
    for (i = 0; i < strsSize; i++) {
        strLen = strlen(strs[i]);
        if (shortLen > strLen) {
            shortLen = strLen;
            shortStr = strs[i];
        }
    }

    for (j = 0; j < shortLen; j++) {
        for (i = 0; i < strsSize; i++) {
            if (strs[i][j] != shortStr[j]) {
                if (j == 0) {
                    return "";
                } else {
                    shortStr[j] = '\0';
                    return shortStr;
                }
            }
        }
    }
    
    if (j == shortLen) {
        return shortStr;
    }

    return "";
}