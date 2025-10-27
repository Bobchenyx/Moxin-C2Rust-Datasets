int lastRemaining(int n, int m){
    if(n==1) return n-1;
    return (lastRemaining(n-1,m)+m)%n;
}