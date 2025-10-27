int longestPalindrome(char * s){

    int times[52]={0};
    int length=0;
    while(*s!='\0')
    {
        if(*s<'a')
            ++times[*s-'A'];
        else
            ++times[*s-'a'+26];
        ++length;++s;
    }

    
    int sum=0;
    for(int i=0;i<52;++i)
        sum+=2*(times[i]/2);

    return length>sum?sum+1:sum;
}