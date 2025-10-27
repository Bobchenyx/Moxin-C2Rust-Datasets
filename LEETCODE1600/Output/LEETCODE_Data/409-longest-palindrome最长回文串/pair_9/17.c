int longestPalindrome(char * s){
    int characters[127] = {0};
    int cnt = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        characters[s[i]]++;
    }
    for(int i = 0; i < 127; i++)
    {
        if(characters[i] / 2 >= 1)
            cnt = characters[i] / 2 * 2 + cnt;
    }
    cnt++;
    if(cnt > strlen(s))
        return strlen(s);
    else
        return cnt;
}