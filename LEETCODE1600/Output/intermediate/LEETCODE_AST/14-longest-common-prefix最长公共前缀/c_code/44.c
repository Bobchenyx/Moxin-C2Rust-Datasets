char * longestCommonPrefix(char ** strs, int strsSize){
    int index=0,j=0;
    char *a=strs[0];
    if(strsSize==0) return "";
    while(1){
        for(j=0;j<strsSize;j++)
            if (strs[j][index]!=strs[0][index]||strs[j][index]==0) break;
        if (j==strsSize) 
            index++;
        else break;
    }
    a[index]='\0';
    return a;
}