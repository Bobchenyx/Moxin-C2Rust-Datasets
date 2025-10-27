int myAtoi(char* str) {
    long lresult = 0;
    long ltmp = 0;
    int iBit = 0;
    int isign = -1; //0为无符号,1为正数,2为负数
    int i;

    for(i=0; str[i]!='\0'; i++)
    {
        if(-1 == isign)
        {
            if(str[i] == '+')
            {
                isign = 1;
            }
            else if(str[i] == '-')
            {
                isign = 2;
            }
            else if((str[i] >= '0') && (str[i] <= '9'))
            {
                isign = 0;
                i--;
            }
            else if(str[i] == ' ' || str[i] == '\"')
            {
                continue;
            }
            else
            {
                lresult = 0;
                break;
            }
        }
        else
        {
            if((str[i] >= '0') && (str[i] <= '9'))
            {
                iBit++;
                ltmp = str[i]-'0';
            }
            else
            {
                break;
            }

            if(INT_MAX < lresult * 10 + ltmp)
            {
                if(2 == isign)
                {
                    lresult = INT_MIN;
                }
                else
                {
                    lresult = INT_MAX;
                }
                break;
            }
            lresult =  lresult * 10 + ltmp;
        }

    }

    if(2 == isign)
    {
        lresult = lresult * (-1);
    }
    return lresult;
}