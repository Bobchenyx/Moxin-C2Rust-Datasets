//----------------------------------------------------------------方法一 暴力
bool isUnique(char* astr){
    if(astr==0||astr=="")return 0;
    
    for(int i=0;astr[i]!='\0';++i)
        for(int j=0;astr[j]!='\0';++j)
            if(i!=j&&astr[i]==astr[j])
                return 0;
    return true;
}

//----------------------------------------------------------------方法三 快速排序 + 异或
void sort(char* Str,int Low,int High)
{
    if(Low<High)
    {
        int i=Low,j=High;char temp=Str[Low];
        while(i!=j)
        {
            while(i<j&&temp<Str[j])--j;
            if(i<j)Str[i++]=Str[j];
            while(i<j&&temp>Str[i])++i;
            if(i<j)Str[j--]=Str[i];
        }
        Str[i]=temp;
        sort(Str,Low,i-1);
        sort(Str,i+1,High);
    }
}
bool isUnique(char* astr){
    if(astr==0||astr=="")return 0;
    int length=0;
    for(int i=0;astr[i]!='\0';++i)
        ++length;
    sort(astr,0,length-1);
    for(int i=0;i+1<length;++i)
        if((astr[i]^astr[i+1])==0)
            return false;
    return true;
}