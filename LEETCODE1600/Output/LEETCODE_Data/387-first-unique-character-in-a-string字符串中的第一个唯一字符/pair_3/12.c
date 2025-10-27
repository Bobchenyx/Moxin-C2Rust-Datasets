int firstUniqChar(char * s)
{
    //暴力解法时间复杂度太高，下面使用官方解法
    //先遍历数组把每个字母出现的次数记录下来，然后就简单了 
    int a[26]={0};
    for(int i=0;i<strlen(s);i++)  a[s[i]-'a']+=1;
    for(int i=0;i<strlen(s);i++) if(a[s[i]-'a']==1) return i;  
    return -1;
}