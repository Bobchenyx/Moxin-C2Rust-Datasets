bool isPalindrome(char * s)
{
    if(s[0]=='\0') return true;//空字符
    int len=strlen(s);
    int j=0;
    char p[len];//只保留字母和数字的字符数组
    for(int i=0;i<len;i++)
    {
        if((s[i]<='z' && s[i]>='a') || (s[i]<='9' && s[i]>='0'))//小写字母和数字直接存
        p[j++]=s[i];
        else if(s[i]<='Z' && s[i]>='A')//把大写字母存成小写
        p[j++]=s[i]+32;
    }
    for(int i=0;i<j/2;i++)
    {
        if(p[i]!=p[j-i-1]) return false;
    }
    return true;


}