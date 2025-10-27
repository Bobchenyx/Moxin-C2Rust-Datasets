long trailingZeroes(int n){
    int tem=n,i;
    long sum=0,a=5;
    for(i=0;i<100;i++)
    {
        if(tem/a==0)
        break;
        sum+=tem/a;
        a*=5;
    }
    return sum;
}