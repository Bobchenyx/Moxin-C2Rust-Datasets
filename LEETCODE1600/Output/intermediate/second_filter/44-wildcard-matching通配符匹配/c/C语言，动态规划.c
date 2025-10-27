bool isMatch(char * s, char * p){
    int len_s = strlen(s), len_p = strlen(p);
    
    int** dp = (int**)malloc(sizeof(int*)*(len_s+1));
    for (int i = 0; i <= len_s; ++i){
        *(dp+i) = (int*)malloc(sizeof(int)*(len_p+1));
        memset(*(dp+i), 0, sizeof(int)*(len_p+1));
    }

    dp[0][0] = 1;
    for (int i = 1; i <= len_p; ++i){ // 考虑边界条件
        if (p[i-1] == '*')
            dp[0][i] = 1;
        else
            break;
    }

    for (int i = 1; i <= len_s; ++i){
        for (int j = 1; j <= len_p; ++j){
            if (s[i-1] == p[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                if (p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*')
                    dp[i][j] = dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j];
            }
        }
    }

    return dp[len_s][len_p];
}