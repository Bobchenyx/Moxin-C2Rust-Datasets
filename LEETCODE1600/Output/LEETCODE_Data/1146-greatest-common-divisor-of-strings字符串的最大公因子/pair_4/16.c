//求最大公约数
int gcd(int l1, int l2){
    if(l2==0)
        return l1;
    else
        return gcd(l2,l1%l2);
}


char * gcdOfStrings(char * str1, char * str2){
    char *tmp1=(char *)calloc(strlen(str1)+strlen(str2)+2, sizeof(int));
    char *tmp2=(char *)calloc(strlen(str1)+strlen(str2)+2, sizeof(int));

    strcpy(tmp1,str1);
    strcat(tmp1,str2);
    
    strcpy(tmp2,str2);
    strcat(tmp2,str1);
    //查看str1+str2 是否等于 str2+str1
    if(strcmp(tmp1,tmp2)!=0)
        return "";
    
    int len1=strlen(str1), len2=strlen(str2);
    int len=gcd(len1,len2);
    
    return str1+len1-len;



}