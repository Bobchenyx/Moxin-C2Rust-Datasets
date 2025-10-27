char * addStrings(char * num1, char * num2){
    int len1=strlen(num1);
    int len2=strlen(num2);
    int unit1=len1-1;//个位数下标
    int unit2=len2-1;
    int cnt=(len1>=len2)?len2:len1;//位数少的那个数决定需要进行多少次累加
    int leftcnt=(len1>=len2)?len1-len2:len2-len1;
    int len=(len1>=len2)?len1+2:len2+2;//存结果的长度，多出两位：一个存可能出现的最高位进位，一个存结束符'\0'
    char *ret=(char*)malloc((len)*sizeof(char));
    int unit=len-2;//len-1下标给了'\0'
    ret[0]=0;
    ret[len-1]='\0';
    int carrybit=0;
    int i=0;
    for(;i<cnt;i++)
    {
        ret[unit-i]=(num1[unit1-i]-'0'+num2[unit2-i]-'0'+carrybit)%10+'0';
        if((num1[unit1-i]-'0'+num2[unit2-i]-'0'+carrybit)>=10)
        {
            carrybit=1;
            continue;
        }
        carrybit=0;//使用完进位，清零
    }
    //接下来处理两个相加数中，较多位数的多出来的高位
    //printf("unit-i: %d\n",unit-i);
    //printf("i:%d\n",i);
    //printf("cnt: %d\n",cnt);
    //printf("leftcnt: %d\n",leftcnt);
    for(;i<cnt+leftcnt+1;i++)//多一位，为新增的保留的最高位进位
    {
        if(i!=cnt+leftcnt)//还有剩余的高位未填
        {
            ret[unit-i]=(len1>=len2)?(num1[unit1-i]-'0'+carrybit)%10+'0':(num2[unit2-i]-'0'+carrybit)%10+'0';
            int temp=(len1>=len2)?(num1[unit1-i]-'0'+carrybit):(num2[unit2-i]-'0'+carrybit);
            if(temp>=10)
            {
                carrybit=1;
                continue;
            }
            carrybit=0;//使用完进位，清零
        }
        else if(carrybit==1)
            ret[unit-i]=carrybit+'0';
    }

    while(*ret==0)//忽略掉开头的空字符
        ret++;
return ret;
}