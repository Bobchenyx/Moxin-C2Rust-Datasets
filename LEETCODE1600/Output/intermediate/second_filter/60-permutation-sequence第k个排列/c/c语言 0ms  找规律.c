int fac(int n)//计算n的阶乘
{
    if(n==0||n==1)
       return 1;
    else
       return fac(n-1)*n;
}
int find(int *flags,int k,int n)//查找flag数组中第k个值为0的数
{
    int num=0;
    int re=0;
    for(int i=1;i<=n;i++)
    {
        if(flags[i]==0)
           num+=1;
        if(num==k)
        {
           re=i;
           break;
        }
    }
    return re;

}
char * getPermutation(int n, int k){
    char *answer=(char*)malloc(sizeof(char)*(n+1));
    int *flags=(int*)malloc(sizeof(int)*(n+1));
    int i=0;
    for(i=0;i<=n;i++)
        flags[i]=0;
    int m=n-1;
    int a=k;
    int b=0;
    int index=0;
    int cur=0;
    while(m!=-1)
    {
        b=a%fac(m);
        a=a/fac(m);
        if(b!=0)
           a=a+1;
        if(b==0)
           b=fac(m);
        index=find(flags,a,n);
        answer[cur]=index+'0';
        flags[index]=1;
        cur+=1;
        m=m-1;
        a=b;
    }
    answer[cur]='\0';
    return answer;
}