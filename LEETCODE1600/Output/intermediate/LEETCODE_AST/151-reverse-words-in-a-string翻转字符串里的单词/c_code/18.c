char * reverseWords(char * s){
    char *str=malloc(100000);
    int k=0;
    int end=strlen(s)-1;

    while(end>=0){
        if(s[end]==' ')end--;
        else{
            int start=end;
            while(start>=0&&s[start]!=' ')start--;
            memcpy(str+k,s+start+1,end-start);
            k+=end-start;
            str[k++]=' ';
            end=start-1;
        }
    }
    if(k>=1)
        str[k-1]='\0';
    else str[k]='\0';
    return  str;
}