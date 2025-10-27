char * toLowerCase(char * str){
    int i=strlen(str);
    char *res=(char*)malloc(sizeof(char)*(i+1));
    res[i]='\0';
    for(i=0;str[i]!='\0';i++){
        //res[i]=str[i]>='A'&&str[i]<='Z'?str[i]+32:str[i];
        res[i]=str[i]|' ';      //实际上用的较少
    }
    return res;
}