int longestPalindrome(char * s)
{
    int c[128]={0},ret=0;
    
    for(int i=0;i<strlen(s);i++)
    {
        c[s[i]]++;
    }

    for(int i=0;i<128;i++)
    {
        ret+=c[i]-c[i]%2;
    }


    return ret+(ret!=strlen(s));
}