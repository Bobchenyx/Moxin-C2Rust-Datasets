char* replaceSpace(char* s){
    int iLen = 0;
    int iSpaceLen = 0;
    int iNewLen;
    int i,j;
    char sTmp[10000] = {0};
    char *pcRet = sTmp;

    if ((void *)0 == s)
        return (char*)(void *)0;

    while ('\0' != s[i])
    {
        iLen++;
        if (' '== s[i])
        {
            iSpaceLen++;
        }
        i++;
    }
    
    iNewLen = iLen + iSpaceLen * 2;

    for(i = iNewLen, j = iLen; (i >= j && j >= 0);)
    {
        if (' ' == s[j])
        {
            sTmp[i--] = '0';
            sTmp[i--] = '2';
            sTmp[i--] = '%';
        }
        else
        {
            sTmp[i--] = s[j];
        }
        j--;
    }

    return pcRet;
}