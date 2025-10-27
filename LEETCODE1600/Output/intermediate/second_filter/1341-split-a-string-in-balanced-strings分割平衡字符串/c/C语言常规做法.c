int balancedStringSplit(char * s){
    short i=0,count=0,sign=0;
    while(s[i]){
        sign=s[i++]=='L'?sign+1:sign-1;
        if(sign==0) count++;
    }
    return count;
}