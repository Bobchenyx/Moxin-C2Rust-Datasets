int numJewelsInStones(char * J, char * S){
    int i,j,ret=0,a=strlen(S),b=strlen(J);

    for(j=0;j<b;j++)
    {
        for(i=0;i<a;i++)
        {
            if(S[i]==J[j])
            ret++;
        }
    }
    return ret;
}