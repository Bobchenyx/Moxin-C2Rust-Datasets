char * longestCommonPrefix(char ** strs, int strsSize){
    int len = 1,i,j;
    if(strsSize==0)return "";
    for(i=0;;i++){
        for(j=0;j<strsSize&&strs[0][i]==strs[j][i]&&strs[j][i]!='\0';j++);
        if(j==strsSize&&strs[0][i]!='\0')len++;
        else break;
        printf("%d ",len);
    }
    
    char* com_pre = (char*)malloc(sizeof(char)*len);
    for(i = 0;i<len-1;i++)
        com_pre[i] = strs[0][i];
    com_pre[i] = '\0';
    return com_pre;
}