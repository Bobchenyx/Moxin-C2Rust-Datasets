bool isValid(char * s){
    char *str = (char *)malloc(sizeof(char) * strlen(s));
    int num = 0;

    while (*s != '\0')
    {
        if (num == 0 || *s == '(' || *s == '[' || *s == '{')
        {
            str[num++] = *s;
        } 
        else if (*s == ')')
        {
            if (str[num - 1] == '(') num--;
            else 
            {   
                free(str);
                return false;
            }
        }
        else if (*s == ']')
        {
            if (str[num - 1] == '[') num--;
            else 
            {   
                free(str);
                return false;
            }
        }
        else if (*s == '}')
        {
            if (str[num - 1] == '{') num--;
            else 
            {   
                free(str);
                return false;
            }
        }
        s++;
    }
    free(str);
    if (num == 0) return true;
    else return false;
}