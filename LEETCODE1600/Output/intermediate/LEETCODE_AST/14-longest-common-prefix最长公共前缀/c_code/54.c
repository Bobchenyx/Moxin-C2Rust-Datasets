char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0) return "";
    int index=0,j;
    while(1){
        for(j=0;j<strsSize;j++)
            if (strs[j][index]!=strs[0][index]||strs[j][index]==0) break;
        if (j==strsSize) index++;
        else break;
    }
    char s[index+1];
    for (j=0;j<index;j++)
        s[j]=strs[0][j];   
    s[index]=0;
    char* str=s;
    return str;
}