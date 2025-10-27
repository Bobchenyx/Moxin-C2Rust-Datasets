int lengthOfLastWord(char * s){
    int i=0,j=strlen(s)-1,flag=0;
    for(i=0;i<=j;i++){
        if(s[i]!=' '){
            flag=1;
            break;
        }
    }
    if(!flag||j<0) return 0;
    while(s[j]==' '){
        j--;
    }
    for(i=j-1;i>=0;i--){
        if(s[i]==' ') break;
    }
    return j-i;
}