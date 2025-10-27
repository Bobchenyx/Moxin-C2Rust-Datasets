char * convertToTitle(int n){
    int tmp=n,len=31;
    char *ch=(char*)malloc(sizeof(char)*(32));
    *(ch+len)='\0';
    while(n>0){
        tmp=(n-1)%26;
        ch[--len]='A'+tmp;
        n=(n-1)/26;
    }
    return ch+len;
}