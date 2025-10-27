char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0) return "";
    char *commonPrefix = *strs;
    for(int i = 1; i < strsSize; i++) {
        int j = 0;
        while(*(commonPrefix + j) != '\0' && *(*(strs + i) + j) != '\0' && *(commonPrefix + j) == *(*(strs + i) + j)) {
            j++;
        }
        *(commonPrefix+j) = '\0';
    }
    return commonPrefix;
}