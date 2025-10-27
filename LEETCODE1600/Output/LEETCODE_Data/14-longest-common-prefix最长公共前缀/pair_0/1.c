char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0) return "";
    char *common;
    common = *strs;
    int i,j;
    for(i=1;i<strsSize;i++){
        for(j=0;j<strlen(strs[i]);j++){
            if(common[j]!=strs[i][j]){
                common[j]='\0';
                break;
            }        
        }
        common[j]='\0';
    }
    return common;
}