double myPow(double x, long n){
    if(n==0){
        return 1;
    }
    if(n<0){
        x=1/x;
    }
    n=n>0?n:-n;
    if(n==1){
        return x;
    }
    double temp=x,res=1;
    long i=1;
    int flag=0;
    do{
        if(n==1){
            flag=1;
            temp=x;
            res*=temp;
            break;
        }else if(i*2<n){
            flag=0;
            temp*=temp;
            i*=2;
        }else{
            flag=1;
            res*=temp;
            n-=i;
            i=1;
            temp=x;
        }
    }while(i<n);
    res*=x;
    return res;
}