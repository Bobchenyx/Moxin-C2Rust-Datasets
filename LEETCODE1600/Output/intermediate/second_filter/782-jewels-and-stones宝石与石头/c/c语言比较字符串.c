int numJewelsInStones(char * J, char * S){
    char *p=J;
    char *q=S;
    int cntj=0,cnts=0;
    int cnt=0;
    while(*p)
    {
        cntj++;
        p++;
    }
    while(*q)
    {
        cnts++;
        q++;
    }
    cnts=strlen(S);
    for(int i=0;i<cntj;i++)
    {
        for(int j=0;j<cnts;j++)
        {
            if(J[i]==S[j])
            {
                cnt++;
            }
            
        }
    }
    return cnt;
}