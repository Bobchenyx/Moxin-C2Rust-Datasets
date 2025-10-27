char *Common(char *str1,char *str2)
{
    int length1=strlen(str1),length2=strlen(str2);
    int index1=0,index2=0;
    //for result
    char *result=(char *)malloc(sizeof(char)*(length1+1));
    int index=0;
    while(index1<length1&&str1[index1]==str2[index2])
    {
        result[index]=str1[index1];
        index++;index1++;index2++;
    }
    result[index]='\0';
    return result;
}
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0)
    return "";
    if(strsSize==1)
    return strs[0];

    int i;
    char *result=(char *)malloc(sizeof(char)*(strlen(strs[0])+1));
    result=Common(strs[0],strs[1]);
    for(i=2;i<strsSize;i++)
    result=Common(result,strs[i]);
    return result;
}