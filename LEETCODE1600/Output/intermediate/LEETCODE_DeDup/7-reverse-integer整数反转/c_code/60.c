int reverse(int x){
    int s[10],count=0,i;
    long m=0;
    for(i=0;x!=0;i++)
    {
        s[i]=x%10;
        x=x/10;
        count++;
    }
    for(i=0;count>0;count--,i++)
    {
        m+=s[i]*pow(10,count-1);
        if(m>2147483647||m<-2147483647)
        {
            m=0;break;
        }
    }
    return m;
}