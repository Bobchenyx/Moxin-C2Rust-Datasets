int balancedStringSplit(char * s){
    int sum=0;
    int i=0;
    int rlsum=0;
    while(s[i]!='\0'){
        if(s[i]=='R'){
            rlsum++;
        }else if(s[i]=='L'){
            rlsum--;
        }
        if(rlsum==0){
            sum++;
            rlsum=0;
        }
        i++;
    }
    return sum;
}