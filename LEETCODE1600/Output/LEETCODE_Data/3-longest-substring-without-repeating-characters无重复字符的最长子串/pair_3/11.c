int lengthOfLongestSubstring(char * s){
    char *p;
    char *q;
    int max_length = 0;
    int length =0;
    p=s;
    q=p;
    char *t;
    t=p;
    if(!*p) return 0;
    while(*(++q)){
        for(t=p;t<q;t++){
            if(*t==*q){
                p=t+1;
                break;
            }
        }
        length = q-p;
        max_length=length>max_length?length:max_length;
       /* for(t=p;t<q;t++){
            printf("%c",*t);
        }
        printf("\n");*/
    }
    return (max_length+1);
}