int firstUniqChar(char * s){
    int hash[26]={0};
    for(char* iter=s;*iter!='\0';++iter)
        ++hash[*iter-'a'];
    for(char* iter=s;*iter!='\0';++iter)
        if(hash[*iter-'a']==1)
            return iter-s;
    return -1;
}