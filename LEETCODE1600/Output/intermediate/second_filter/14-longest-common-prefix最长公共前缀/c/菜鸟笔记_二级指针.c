char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0)
        return "";
    int i, j;
    char* ans = strs[0];

    for (i = 1; i < strsSize; i++){
        for (j = 0; ans[j] == strs[i][j] && ans[j] != '\0'; j++ ){
            //空
        }
        ans[j] = '\0';
    }
    return ans;
}