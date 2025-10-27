char * defangIPaddr(char * address)
{
    //入参检查
    if(address == NULL)
    {
        return NULL;
    }
    //IP地址的格式中仅有4个'.'
    int len = strlen(address) + 4*2;
    char *result = (char*)malloc(sizeof(char)*len);
    memset(result,0,sizeof(char)*len);

    int j = 0;
    for(int i = 0;i<strlen(address);i++)
    {
        if(address[i] == '.')
        {
            result[j++] = '[';
            result[j++] = '.';
            result[j++] = ']';
        }
        else
        {
            result[j++] = address[i];
        }
    }
    return result;
}