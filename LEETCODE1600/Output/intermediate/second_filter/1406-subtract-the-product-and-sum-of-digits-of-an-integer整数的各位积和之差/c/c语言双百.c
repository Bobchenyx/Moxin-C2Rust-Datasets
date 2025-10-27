int subtractProductAndSum(int n){
    int sums=0,mul=1,result=0;
    while(n!=0){
        sums+=n%10;
        mul*=n%10;
        n/=10;
    }
    result=mul-sums;
    return result;
}