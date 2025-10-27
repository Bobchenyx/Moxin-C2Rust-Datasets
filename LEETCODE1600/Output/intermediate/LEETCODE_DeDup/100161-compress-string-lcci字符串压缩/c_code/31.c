char* compressString(char* S){
    char s[333333] =  {0};
    s[0] = S[0];
    char c = S[0];
    int i,j=1 ,n = strlen(S);
    if(n <= 2)
        return S;
    int count = 1;
    for(i = 1; i < n; i++)
    {
        if(S[i] == c)
            count ++;
        else
        {
            j = jia(s, j , count);
            s[j++] = S[i];
            count = 1;
            c = S[i]; 
        }
    }
     j = jia(s, j , count);
    return (strlen(s) < n? s:S);
}
int jia(char * s, int j ,int num)
{
    if(num < 10)
    {
        //*(s + j) = num+'0';
        //j++;
        s[j++] = num+'0';
        return j;
    }
    j = jia( s , j ,num/10);
    //*(s + j) = num%10+'0';
    //j++;
    s[j++] = num%10+'0';
    return j;
}