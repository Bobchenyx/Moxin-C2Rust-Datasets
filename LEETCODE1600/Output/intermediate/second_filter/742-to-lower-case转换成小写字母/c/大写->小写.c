char * toLowerCase(char * str){
    char *iter=str;
    while(*iter!='\0')
    {
        if(*iter<='Z'&&*iter>='A')
        *iter=(char)((int)(*iter)+32);
        iter++;            
    }
    return str;
}