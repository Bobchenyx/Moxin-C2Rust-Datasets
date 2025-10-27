char * removeOuterParentheses(char * S){
    int i=-1,n=0,m=0;
    char b;
    while(b=S[m++])
    {
        if(b=='(')
        {
            if(i==-1)
                i++;
            else
            {
                i++;
                S[n++]=b;
            }
        }
        if(b==')')
        {
            if(i==0)
                i--;
            else
            {
                i--;
                S[n++]=b;
            }
        }
    }
    S[n]='\0';
    return S;
}