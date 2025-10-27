int numDecodings(char * s){
    int length=strlen(s),count=0;
    if(s[0]=='0')//处理给的数字是0的情况，因为0没有对应的方法。
    return 0;
    if(length<2)
    return 1;
    else//大于等于2
    {
        if((s[0]-'0')*10+(s[1]-'0')<=26)//这里比如满足数小于26才能够调用
        count+=(numDecodings(s+2));
        count+=numDecodings(s+1);
       //count+=numDecodings(s+3); 

    }
    return count;
}