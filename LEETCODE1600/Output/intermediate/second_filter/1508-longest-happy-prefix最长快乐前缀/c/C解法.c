char * longestPrefix(char * s){
    int i;
    int len = strlen(s);
    for(i=len-1; i>0; i--){
        if(!memcmp(s, s + len - i , i)) break;
    }
    printf("%d",i);
    s[i] = '\0';
    return s;
}