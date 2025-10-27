int longestPalindrome(char * s)
{
    if(s == NULL)
        return 0;
    int len_s = strlen(s);
    char *test = NULL;
    int i,j;
    int num = 1,flag1 = 0,ret = 0;

    test = (char*)malloc(len_s);
    test = s;
    char val = test[0];

    for(i = 0;i<len_s;i++)
    {
        j = 0;
        if(test[i] != 1)
        {

            for(j = i+1;j<len_s;j++)
            {
                if(test[j] == test[i])
                {
                    test[j] = 1;
                    num++;
                }   
            }
            
            if(num%2 == 0)
            {
                ret += num;
                num = 1;
            }
            else
            {
                ret += (num/2)*2;
                flag1 = 1;
                num = 1;
            }
        }     
    }
    if(flag1 == 1)
        return ret+1;

    return ret;

}