int subtractProductAndSum(int n){
    int sum=0,mul=1;
    while(n!=0)
    {
        int num=n%10;
        n/=10;
        sum+=num;
        mul*=num;
    }
    return mul-sum;
}