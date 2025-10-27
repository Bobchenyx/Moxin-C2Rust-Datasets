bool isPalindrome(int x){
    int k=0;
    long t=x;
    if(x<0)
    return false;
    while(t!=0)
    {
        k++;//数字位数
        t=t/10;
    }
    t=x;
    long y=0;//重构其回文数
    int i,j=k,p,w;
    for(i=0;i<k;i++)
    {
        w=1;
        for(p=0;p<j-1;p++)
            w=w*10;
        y=y+t%10*w;
        t/=10;
        j--;
    }
    if(x==y)
    return true;
    return false;
}