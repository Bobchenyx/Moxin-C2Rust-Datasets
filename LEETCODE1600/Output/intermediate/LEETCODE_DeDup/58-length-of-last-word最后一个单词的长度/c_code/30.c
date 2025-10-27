int lengthOfLastWord(char * s)
{
    int len = strlen(s);
    int i,j,n=0;
    int f = 0;
    if(len == 0)
    {
        return 0;
    }

    for(i = len -1; i >0;i--)
    {
        if(s[i] != ' ')
        {
            break;
        }
        else
        {
            f++;
        }
    }

    for(i = len -f - 1; i >= 0; i--)
    {
        if(s[i] == ' ')
        {
            break;
        }
    }
    n = len - f - i - 1;

    return n;
}