bool detectCapitalUse(char * word){
    int i=0,a=0;
    while(word[i]!=NULL)
    {
        if(word[i]>='A'&&word[i]<='Z')
            a=a+1;
        if(word[i]>='a'&&word[i]<='z')
            a=a+0;
        i++;
    }
    if(word[0]>='A'&&word[0]<='Z'){
        if(i==a||a==1)
            return true;
    }
    if(word[0]>='a'&&word[0]<='z'){
        if(a==0)
            return true;
    }
    return false;
}