char * toLowerCase(char * str){
    int length=strlen(str),i;
    for(i=0;i<length;i++){
        if((str[i]-'a')<0&&(str[i]-'A')>=0&&(str[i]-'A')<=25)
            str[i]+=32;
    }
    return str;
}