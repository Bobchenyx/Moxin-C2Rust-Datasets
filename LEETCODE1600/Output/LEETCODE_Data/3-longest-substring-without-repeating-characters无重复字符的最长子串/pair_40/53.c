// 此代码中的dp[i]其实是不必要的, 因为计算dp[i]时只需要dp[i-1]即可
int lengthOfLongestSubstring(char * s){
    int size = strlen(s);
    if(size == 0){
        return 0;
    }
    int dp[size], idx[256];          // dp[i]是以s[i]结尾的最长非重复子串长度
    memset(idx, -1, sizeof(idx));    // idx[c]用于记录字符c最后出现的位置
    dp[0] = 1, idx[s[0]] = 0;
    for(int i = 1; i < size; i ++){
        int pre_start_idx = i - 1 - dp[i - 1];
        dp[i] = idx[s[i]] > pre_start_idx ? dp[i] = i - idx[s[i]] : dp[i - 1] + 1;
    ¦   idx[s[i]] = i; 
    }
    int ans = 0;
    for(int i=0; i < size; i ++){
        ans = dp[i] > ans ? dp[i] : ans;
    }
    return ans;
}