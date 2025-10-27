char * longestCommonPrefix(char ** strs, int strsSize){
    int i=0,j=0;
    if(strsSize==0) {
        return "";
    }
    if(strsSize==1) {
        return *strs;
    }
    char *ans=strs[0];
    for(i=1;i<strsSize;i++){
        for(j=0;ans[j]!='\0'&&strs[i][j]!=0;j++){
            if(ans[j]!=strs[i][j]) break;
        }
        ans[j]='\0';
        if(ans==NULL) return "";
    }
    return ans;
    
}