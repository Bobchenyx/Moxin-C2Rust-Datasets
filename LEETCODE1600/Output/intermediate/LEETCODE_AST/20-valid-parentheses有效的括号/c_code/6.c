bool isValid(char * s){
    int length=strlen(s);//获取字符长度
    if(length==0)//别用'\0'判断
    return true;
    char *mark=(char *)malloc(sizeof(char)*length);//建立一个标记数组
    int i,count=-1;
    for(i=0;i<length;i++)
    {
        if(*(s+i)==')')
            if(count>-1&&*(mark+count)=='(')
            count--;
            else 
            return false;
        else if(*(s+i)=='}')
            if(count>-1&&*(mark+count)=='{')
            count--;
            else 
            return false;
        else if(*(s+i)==']')
            if(count>-1&&*(mark+count)=='[')
            count--;
            else 
            return false;
        else
            mark[++count]=s[i];
    }
    if(count>-1)
    return false;
    return true;
}