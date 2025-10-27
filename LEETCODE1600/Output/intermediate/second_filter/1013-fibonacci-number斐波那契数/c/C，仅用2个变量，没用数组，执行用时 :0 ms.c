int fib(int N){    
    if(N==0||N==1) return N;
    int a=0,b=1;
    for(int i=2;i<=N;i++){
        b=a+b;
        a=b-a;        
    }
    return b;
}