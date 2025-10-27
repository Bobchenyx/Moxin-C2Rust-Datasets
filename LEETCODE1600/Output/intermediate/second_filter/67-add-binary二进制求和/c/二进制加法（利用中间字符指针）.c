char * addBinary(char * a, char * b){

    int length = 0;
    int lengthDif = 0;  //长度差值
    int i;
    char* c = NULL;
    char flag = 0;  //进位标志
    length = ((strlen(a) >= strlen(b))? (strlen(a)+2): (strlen(b)+2));

    c  = (char*)malloc(sizeof(char)*length);
    c[length-1] = '\0';
    lengthDif = (length-1) - strlen(a);
    for(i = (length-2); i >= 0; i--)
    {
        if(i >= (length-1-strlen(a)))
            c[i] = a[i-lengthDif];
        else
            c[i] = '0';
    }

    lengthDif = (length-1) - strlen(b);
    for(i = (length-2); i >= 0; i--)
    {
        if(i >= (length-1-strlen(b)))
        {
            if((c[i] + b[i-lengthDif] - '0') > '1')
            {
                if(flag)
                {
                    c[i] = '1';
                }
                else
                {
                    c[i] = '0';
                    flag = 1;
                }
            }
            else if((c[i] + b[i-lengthDif] - '0') == '1')
            {
                if(flag)
                {
                    c[i] = '0';
                }
                else
                    c[i] = '1';
            }
            else if((c[i] + b[i-lengthDif] - '0') == '0')
            {
                if(flag)
                {
                    c[i] = '1';
                    flag = 0;
                }
                else
                    c[i] = '0';
            }
        }
        else if(flag == 0)
        {
            ;
        }
        else
        {
            if(c[i] == '1')
            {
                c[i] = '0';
            }
            else if(c[i] == '0')
            {
                c[i] = '1';
				flag = 0;
            }
        }
    }

    if(c[0] == '0')
        return c+1;
    else
        return c;
}