char * defangIPaddr(char * address){
    int i,length=0,sign=0;
    while(address[length]!=0)
        length++;
    char s[length+7];
    s[length+6]=0;
    for(i=0;i<length;i++){
        if(address[i]=='.'){
            sign++;
            s[i+sign*2-2]='[';
            s[i+sign*2-1]='.';
            s[i+sign*2]=']';
        }
        else s[i+sign*2]=address[i];
    }
    char *str;
    str=s;
    return str;
}