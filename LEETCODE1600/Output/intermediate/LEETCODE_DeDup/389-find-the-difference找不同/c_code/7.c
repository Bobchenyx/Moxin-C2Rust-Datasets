char findTheDifference(char * s, char * t){
    int hash[26]={0};
    for(char* iter=s;*iter!='\0';++iter)
        ++hash[*iter-'a'];
    for(char* iter=t;*iter!='\0';++iter)
        --hash[*iter-'a'];
    for(int i=0;i<26;++i)
        if(hash[i]!=0)
            return 'a'+i;
    return '\0';
}