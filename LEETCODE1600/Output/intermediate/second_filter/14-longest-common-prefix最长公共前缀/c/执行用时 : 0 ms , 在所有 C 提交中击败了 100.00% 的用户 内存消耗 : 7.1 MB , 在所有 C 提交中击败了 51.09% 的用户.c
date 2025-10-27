char *findMin(char *str1,char *str2)
{
    int length=0;
    char *p1=str1,*p2=str2;
    while(*p1==*p2&&*p2!='\0')//找出最小相同子串的长度
    {
        length++;
        p1++;p2++;
    }
    char *str3=(char *)malloc(sizeof(char)*(length+1));
    for(int i=0;i<length;i++)
        str3[i]=str1[i];
    str3[length]='\0';
    return str3;   
}
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0)
    return "";
    if(strsSize==1)
    return *strs;
    int i;
    char *p=*strs;
    for(i=1;i<strsSize;i++)
    {
        if(*p=='\0')
            return "";
        else
            p=findMin(p,*(strs+i));
    }
    return p;
}