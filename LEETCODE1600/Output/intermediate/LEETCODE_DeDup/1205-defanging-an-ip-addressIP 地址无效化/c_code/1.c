char * defangIPaddr(char * address){
    int i=0,k=0;
    char* res=(char*)malloc((strlen(address)+7)*sizeof(char));
    while(address[i]!='\0'){
        if(address[i]=='.'){
            res[i+2*k]='[';
            res[i+2*k+1]='.';
            res[i+2*k+2]=']';
            k++;
        }else{
            res[i+2*k]=address[i];
        }
        i++;
    }
    res[i+6]='\0';
    return res;
}