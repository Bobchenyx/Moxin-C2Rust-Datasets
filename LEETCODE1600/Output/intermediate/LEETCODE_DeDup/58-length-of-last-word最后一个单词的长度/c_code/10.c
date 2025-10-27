int lengthOfLastWord(char * s){
    int l;
    int i;
    int res = 0;

    if(NULL == s)
        return 0;

    l = strlen(s);
    for(i = l-1; i >=0; i--)
    {
        if(isalpha(s[i]))
            res++;
        else
            if(res)
                break;
    }

    return res;
}