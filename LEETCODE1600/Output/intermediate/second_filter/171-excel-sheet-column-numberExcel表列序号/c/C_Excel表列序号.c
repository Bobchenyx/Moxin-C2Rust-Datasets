int titleToNumber(char * s){
    int result=0;
    while(*s!='\0')
    {
        result=result*26+(*s-'A'+1);    
        ++s;    
    }
    return result;
}