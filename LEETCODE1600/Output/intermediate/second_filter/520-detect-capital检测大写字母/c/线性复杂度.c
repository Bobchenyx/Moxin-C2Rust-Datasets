bool detectCapitalUse(char * word){
    int len;
    int i=0;
    len=strlen(word);
    if(len==0||len==1){
        return true;
    }
    while(i<len&&word[i]>='A'&&word[i]<='Z'){
        i++;
    }
    if(i==len){
        return true;
    }
    i=1;
    while(i<len&&word[i]>='a'&&word[i]<='z'){
        i++;
    }
    if(i==len){
        return true;
    }
    return false;
}