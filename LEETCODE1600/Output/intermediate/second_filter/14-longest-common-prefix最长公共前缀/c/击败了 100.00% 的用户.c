char * longestCommonPrefix(char ** strs, int strsSize){
    int i, j = 0;

    if (strsSize == 0) return "\0";

    while (strs[0][j] != '\0') 
    {
        for (i = 0; i < strsSize; i++)
        {
            if (strs[i][j] == '\0' || strs[i][j] != strs[0][j]) 
            {
                strs[0][j] = '\0';
                return strs[0];
            }
        }
        j++;
    }
    return strs[0];
}