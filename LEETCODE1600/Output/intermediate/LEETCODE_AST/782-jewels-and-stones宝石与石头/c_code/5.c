int numJewelsInStones(char * J, char * S)
{
    int i=0,t=0,flag=0;
    while(J[i]!='\0')
    {
        t=0;
        while(S[t]!='\0')
        {
            if(J[i]==S[t])
            {
                flag++;
            }
            t++;
        }
        i++;
    }
    return flag;
}