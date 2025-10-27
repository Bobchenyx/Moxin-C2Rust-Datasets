char* replaceSpace(char* s)
{
    if(!s)
        return NULL;
    char *str = (char *)malloc(10005*sizeof(char*));
    strcpy(str,s);
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ' ')
        {
            for(int j = len; j >= i+1; j--)
            {
                str[j+2] = str[j];
            }
            len+=2;
            str[i] = '%';
            str[i+1] = '2';
            str[i+2] = '0';
            i = i+2;
        }
        
    }
    str[len] = '\0';
    return str;
}