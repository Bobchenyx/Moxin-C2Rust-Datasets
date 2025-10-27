const long long int m=1000000007;
int prime(int n){
    if(n==1)return 0;
    int i;
    for(i=2;i<(n/2)+1;i++)
    if(n%i==0)return 0;
    return 1;
}
int numPrimeArrangements(int n){
        int i,p=0,q;
        long long int jq=1,jp=1;
        for(i=1;i<=n;i++) if(prime(i)==1)p++;//i是质数
        q=n-p;
        for(i=1;i<=q;i++) jq=(jq*i)%m;
        for(i=1;i<=p;i++)jp=(jp*i)%m;
        return (jp*jq)%m;
}