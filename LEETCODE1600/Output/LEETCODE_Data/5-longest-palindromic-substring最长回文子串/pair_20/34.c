char * longestPalindrome(char * s){
    int n = strlen(s);
    if(n<=1){
        return s;
    }
    int dp[n][n];
    int star=0,len=1;//分别表示答案子串在s中开始下标和答案子串长度
    for(int i=0;i<n-1;i++){
        dp[i][i] = 1;
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            star = i;
            len = 2;
        }else{
            dp[i][i+1] = 0;
        }
    }dp[n-1][n-1] = 1; //初始化长度为1和2的子串的dp
    for(int i=2;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(dp[j+1][j+i-1]==1 && s[j]==s[j+i]){
                dp[j][j+i] = 1;
                star = j;
                len = i+1;
            }else{
                dp[j][j+i] = 0;
            }
        }
    }
    char* result = (char*)malloc(sizeof(char)*(len+1));
    for(int i=0;i<len;i++){
        result[i] = s[star++];
    }
    result[len] = '\0';//字符串最后一个得是0
    return result;
}