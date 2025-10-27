int TwoNum(char a, char b)
{
    if (a == '0') {
        return 0;
    }
    else if (a == '1') {
        return b == '0' ? 1 : 2;
    }
    else if (a == '2') {
        if (b == '0') {
            return 1;
        }
        else {
            return b > '6' ? 1 : 2;
        }
    }
    else {
        return b == '0' ? 0 : 1;
    }
}

int IsAlaph(char a, char b)
{
    if (a == '1') {
        return 1;
    } else if (a == '2') {
        return b > '6' ? 0 : 1;
    } else {
        return 0;
    }
}

int numDecodings(char * s)
{
    int len = strlen(s);
    if (len == 1) {
        return s[0] == '0' ? 0 : 1;
    }
    if (len == 2) {
        return TwoNum(s[0], s[1]);
    }
    int i = 0;
    int dp[100000] ={0};
    dp[0] = s[0] == '0' ? 0 : 1;
    dp[1] = TwoNum(s[0], s[1]);
    for (i = 2; i < len; i++) {
        if (s[i] != '0') {
            dp[i] += dp[i-1];
        }
        if (IsAlaph(s[i-1], s[i]) == 1) {
            dp[i] += dp[i-2];
        }
    }
    return dp[i-1];
}