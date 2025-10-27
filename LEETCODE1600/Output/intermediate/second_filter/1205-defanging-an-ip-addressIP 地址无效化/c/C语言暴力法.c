char * defangIPaddr(char * address){
    char* result=(char*)malloc(sizeof(char)*(strlen(address)+7));
    int k=0;
    int i;
    for ( i=0 ; i<strlen(address) ; i++)
    {
        if (address[i]=='.')
        {
            result[k]='[';
            k++;
            result[k]=address[i];
            k++;
            result[k]=']';
            k++;
        }
        else
        {
            result[k]=address[i];
            k++;
        }
    }
    result[i+6]='\0';
    return result;
}