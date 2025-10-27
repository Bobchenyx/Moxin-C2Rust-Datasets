char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        return "";
    }
    int pivotLen = strlen(strs[0]);
    int i, j;
    int num = pivotLen;
    for (i = 1; i < strsSize; i++) {
        j = 0;
        while (strs[i][j] == strs[0][j] && strs[i][j] != '\0') {
            j++;
        }
        num = j < num ? j : num;
    }
    char *ret = (char*)malloc(sizeof(char) * (num + 1));
    for (i = 0; i < num; i++) {
        ret[i] = strs[0][i];
    }
    ret[i] = '\0';
    return ret;
}