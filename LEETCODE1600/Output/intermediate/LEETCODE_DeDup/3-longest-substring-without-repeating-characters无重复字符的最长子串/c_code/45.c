bool Unique(char *s,int i,int j)
{
    int flag[128] = {0};
    int n;
    for(n=i;n<=j;n++)
    {
        if(!flag[*(s+n)])
        {
            flag[*(s+n)] = 1;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int lengthOfLongestSubstring(char * s){
    int i,j;
    int max = 0;
    int len = strlen(s);
    int n = 0;
    for(i=0;i<len;i++)
    {
        for(j=i;j<len;j++)
        {
            if(Unique(s,i,j))
            {
                n++;
            }
            else
            {
                break;
            }
        }
        max = max>n ? max:n;
        n = 0;
    }
    return max;
}