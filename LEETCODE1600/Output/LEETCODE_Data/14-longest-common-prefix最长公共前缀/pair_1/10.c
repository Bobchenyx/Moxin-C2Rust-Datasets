char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) 
        return "";
        
    if (strsSize == 1)
        return strs[0];
    
    int i = 0, j = 0;
    int len = strlen(strs[0]);
    char *ret = malloc(len + 1);
    strcpy(ret, strs[0]);
    
    for (i = 1; i < strsSize; i++) {
        for (j = 0; j < len; j++) {
            if (strs[i][j] != ret[j]) {
                len = j;
                break;
            }
        }
        if (len == 0)
            return "";
    }
    
    // for (j = 0; j < len; j++) {
    //     for (i = 1; i < strsSize; i++) {
    //         if (strs[i][j] != ret[j])
    //             goto err;
    //     }
    // }

err:
    ret[j] = '\0';
    return ret;
}