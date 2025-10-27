int minValue(int a, int b, int c){
    return (a<b?a:b)>c?c:(a<b?a:b);
}

int dp[100][100] = {0};

int calculate(char * word1, char * word2, int add1, int add2){
    if(strlen(word1) == 0)  return strlen(word2);
    if(strlen(word2) == 0)  return strlen(word1);
    if(dp[add1+1][add2] == 0){
        dp[add1+1][add2] = calculate(word1+1, word2, add1+1, add2);
    }
    if(dp[add1][add2+1] == 0){
        dp[add1][add2+1] = calculate(word1, word2+1, add1, add2+1);
    }
    if(dp[add1+1][add2+1] == 0){
        dp[add1+1][add2+1] = calculate(word1+1, word2+1, add1+1, add2+1);
    }
    return minValue(dp[add1+1][add2]+1, dp[add1][add2+1]+1, dp[add1+1][add2+1]+(int)(word1[0] != word2[0]));
}


int minDistance(char * word1, char * word2){
    return calculate(word1, word2, 0, 0);
}