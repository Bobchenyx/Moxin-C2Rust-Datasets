int isPrime(int i){
    if(i<2){
        return 0;
    }
    int x=2;
    while(x*x<=i){
        if(i%x==0){
            return 0;
        }
        x++;
    }
    return 1;
}
long long jiecheng(int i){
    long long sum=1;
    while(i>1){
        sum=(sum*i)%1000000007;
        i--;
    }
    return sum;
}
int numPrimeArrangements(int n){
    long sum=0,i=1;
    while(i<=n){
        sum+=isPrime(i);
        i++;
    }
    long long res=jiecheng(sum)*jiecheng(n-sum)%1000000007;
    return res;
}