char * toLowerCase(char * str){
    char *p;
    p = str;
    for(;*p!='\0';p++)
    {
        if((int)*p < 91 && (int)*p > 64)
        {
            *p = (int)*p + 32;
        }
    }
    return str;
}