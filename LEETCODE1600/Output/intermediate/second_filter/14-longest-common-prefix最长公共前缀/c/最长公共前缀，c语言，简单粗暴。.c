//char**就是字符串的数组,strs[strsSize][]，而char[][]的长度用'\0'判断
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0){
        return "";
    }
    if(strsSize==1){
        return strs[0];
    }
    int n=strlen(strs[0]),j=0; 
    //n表示当前参与比较了的字符串的公共前缀长度，初始化为第一个串的长度，就可以避免第一次比较数组越界了，无需再判断。
    for(int i=1;i<strsSize;i++){
        j = 0;
        while(strs[0][j]==strs[i][j] && j<n){
            j++;
        }
        n = j;
    }
    char* result = (char*)malloc(sizeof(char)*(n+1));
    for(int k=0;k<n;k++){
        result[k] = strs[0][k];
    }
    result[n] = '\0';
    return result;
}