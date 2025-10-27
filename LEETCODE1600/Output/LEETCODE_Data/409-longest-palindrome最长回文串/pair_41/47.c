int longestPalindrome(char * s){
    if((*s)=='\0')
        return 0;
    int alphabet_lower[26];
    int alphabet_upper[26];
    for(int i=0;i<26;i++)
    {
        alphabet_lower[i]=0;
        alphabet_upper[i]=0;
    }
    while((*s)!='\0')
    {
        if((*s)>='a'&&(*s)<='z')
        {
            alphabet_lower[((*s)-'a')]++;

        }
        else
        {
            alphabet_upper[(*s)-'A']++;

        }
        s++;
    }
    int cnt=0;
    bool flag=false;
    for(int i=0;i<26;i++)
    {
        if(alphabet_upper[i]>=2)
        {
            cnt+=alphabet_upper[i]/2;

        }
        if(alphabet_lower[i]>=2)
        {
            cnt+=alphabet_lower[i]/2;

        }
        if(!flag&&(alphabet_lower[i]%2||alphabet_upper[i]%2))
            flag=true;
    }
    if(!flag)
    {
        
        return cnt*2;
    }
    else
        return cnt*2+1;

}