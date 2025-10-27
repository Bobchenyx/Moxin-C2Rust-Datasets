int balancedStringSplit(char * s){
    char* p=s;
    int sum=0;
    int cnt=0;
    int a=0,b=0;
    while(*p)
    {
        cnt++;
        p++;
    }
    for(int i=0;i<cnt;i++)
    {
        if(s[i]=='R')
        {
            a++;
        }
        else
        {
            b++;
        }
        while(a==b)
        {
            sum++;
            break;
        }
    }
    return sum;
}