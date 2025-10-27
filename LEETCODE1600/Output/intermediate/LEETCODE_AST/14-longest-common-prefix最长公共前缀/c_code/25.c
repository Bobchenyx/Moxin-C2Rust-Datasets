char * longestCommonPrefix(char ** strs, int strsSize){
    char *cmp = NULL;
    int i, j, sz;

    if (strsSize <= 0) {
        return "";
    }

    sz = strlen(strs[0]);

    /* i表示行号 */
    for (i = 1; i < strsSize; i++) {
        /* j表示列对比 */
        for (j = 0; j < sz && j < strlen(strs[i]); j++) {
            if (strs[0][j] != strs[i][j]) {
                break;
            }
        }
        if (j == 0) {
            sz = 0;
            break;
        } else {
            sz = j; 
        }
    }

    if (sz == 0) {
        return "";
    } else {
        cmp = (char *)malloc(sizeof(char) * (sz + 1));
        memset(cmp, '\0', sizeof(char) * (sz + 1));
        strncpy(cmp, strs[0], sz);
    }

    return cmp;
}