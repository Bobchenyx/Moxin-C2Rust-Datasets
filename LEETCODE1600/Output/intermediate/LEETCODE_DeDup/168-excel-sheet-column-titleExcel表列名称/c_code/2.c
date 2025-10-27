#define MaxSize 11
void reverse(char *result,int length)
{
    int i;
    char temp;
    for(i=0;i<length/2;i++)
    {
        temp=result[i];
        result[i]=result[length-i-1];
        result[length-i-1]=temp;
    }
}
char * convertToTitle(int n){
    int base=26;
    int remainder;
    int length=11;
    char *result=(char *)malloc(sizeof(char)*(length));

    length=0;
    while(n>26)
    {
        remainder=n%(base);
        if(remainder==0)//26的倍数
        {
            remainder=26;
            n--;
        }
        result[length++]=remainder+'A'-1;
        n/=base;
    }
    result[length++]=n+'A'-1;
    result[length]='\0';
    reverse(result,length);
    return result;
}