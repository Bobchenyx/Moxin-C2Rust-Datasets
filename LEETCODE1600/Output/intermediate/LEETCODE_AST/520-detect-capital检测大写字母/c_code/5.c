bool detectCapitalUse(char * word){
    int s,b;
    s=*word>'Z'?1:0;
    for(int i=1;i<strlen(word);i++){
        if(s){
            if(word[i]<'a')
            return 0;
        }
        else{
            b=word[1]<'a'?1:0;
            if((word[i]>'Z'&&b)||(word[i]<'a'&&b==0))
            return 0;
        }
    }
    return 1;
}