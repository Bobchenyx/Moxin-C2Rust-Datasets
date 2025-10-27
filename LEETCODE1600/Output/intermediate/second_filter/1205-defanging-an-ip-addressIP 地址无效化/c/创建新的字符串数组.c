char * defangIPaddr(char * address){
    char* p=malloc(sizeof(char)*25);
    char *s=p;
    while(*address)
    {
        if(*address=='.')
        {
            *p++='[';
            *p++='.';
            *p++=']';
            address++;
        }
        else
        {
            *p++=*address;
            address++;
        }
    }
    *p='\0';
    return s;
}