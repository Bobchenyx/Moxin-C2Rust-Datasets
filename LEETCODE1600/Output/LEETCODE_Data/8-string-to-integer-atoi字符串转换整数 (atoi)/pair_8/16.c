//常规方法
int myAtoi(char * str){
    long result=0;
    int length=strlen(str);
    int index=0;

    //删除空格
    while(str[index]==' ')
    index++;
    //判断符号
    int sign=1;
    if(str[index]=='-')//负号
    {
        index++;
        sign=0;
    }
    else if(str[index]=='+')//正号
        index++;
    
    //获取数字
    while(str[index]>='0'&&str[index]<='9')
    {
        result=result*10+str[index]-'0';
        index++;
        if(result>INT_MAX)//防止数据大
        break;
    }
    //添加符号
    if(sign==0)
    result=~result+1;
    
    //判断是否越界
    if(result>INT_MAX)
    return INT_MAX;
    if(result<INT_MIN)
    return INT_MIN;
    return result;

}