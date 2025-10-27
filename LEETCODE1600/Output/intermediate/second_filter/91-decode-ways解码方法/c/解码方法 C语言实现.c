int numDecodings(char * s){
    if (s[0] == '0' || s[0] == 0) return 0;
    int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
    for (int i = 1; s[i] != 0; i++) {
        int tmp = curr;
        if (s[i] == '0')
            if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre; //dp[i] = dp[i-2]
            else return 0; // error
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            curr = curr + pre;  // dp[i] = dp[i-1] + dp[i-2]
        pre = tmp;  // next dp[i-2] = dp[i-1] 
    }
    return curr;
}