bool isUnique(char* astr){
    char *p,*q;
    for(p=astr;*p!='\0';p++){
        for(q=p+1;*q!='\0';q++){
            if(*p==*q){
                 return false;
            }
        }
    }
return true;
}