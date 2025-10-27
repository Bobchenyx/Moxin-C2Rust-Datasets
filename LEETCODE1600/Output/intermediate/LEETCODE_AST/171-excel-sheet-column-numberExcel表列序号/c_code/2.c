int titleToNumber(char * s){
    int sum=0;
    while(*s!='\0'){
        sum=sum*26+(*s-'A'+1);
        s++;
    }
    return sum;

}