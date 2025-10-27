char* removeOuterParentheses(char* S)
{
    int   flag   = 0;
    int   flag_l = 0;
    char* n      = malloc(strlen(S) + 1);
    int   idx    = 0;
    memset(n, 0, strlen(S) + 1);
    while(*S)
    {
        if(*S == '(')
            flag++;

        if(*S == ')')
            flag--;

        if((flag_l == 0) && (flag == 1))
            S++;
        else if((flag_l == 1) && (flag == 0))
            S++;
        else
        {
            n[idx++] = *S;
            S++;
        }
        flag_l = flag;
    }
    return n;
}