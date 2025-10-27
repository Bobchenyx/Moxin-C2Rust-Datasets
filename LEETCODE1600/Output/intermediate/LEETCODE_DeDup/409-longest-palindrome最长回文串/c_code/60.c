int longestPalindrome(char * s){
    int cnt, count, L, i, j;
    count = 0;
    cnt = 0;
    L = strlen(s);
    for(i=0;i<L;i++)
    {
        if(s[i] == '0')
            continue;
        cnt = 1;
        for(j=i+1;j<L;j++)
        {
            if(s[j] == s[i])
            {
                s[j] = '0';
                cnt += 1;
            }
                
        }
        cnt = cnt % 2 ? (cnt-1):cnt;
        count += cnt;
    }
    if(count < L)
        return count + 1;
    return count;
}