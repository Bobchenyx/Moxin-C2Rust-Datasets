char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0) return "";
    int i=0,j=0,num=strlen(strs[0]);