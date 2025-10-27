char* replaceSpace(char* s){
    int len;
    char *str = NULL;
    char *temp = NULL;

    len = strlen(s);

    /* 长度加 '\0' */
    str = (char *)calloc(3*len + 1, sizeof(char));
    if (NULL == str)
        return NULL;

    temp = str;
    
    while (*s)
    {
        if (*s == ' ')
        {
            *str++ = '%';
            *str++ = '2';
            *str++ = '0';
        }
        else
            *str++ = *s;
            
        s++;
    }

    return temp;
}