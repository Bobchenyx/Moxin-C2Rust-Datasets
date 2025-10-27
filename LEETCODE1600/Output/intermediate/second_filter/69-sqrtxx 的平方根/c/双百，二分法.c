int mySqrt(int x){
    if(x==0) return 0;
    if(x<4) return 1;
    if(x<0) return NULL;
    int a=0,b=x/2;
    long m;
    while(b>=a){
        m=(a+b)/2;
        if(m*m<x){
            a=m+1;
        }else if(m*m>x){
            b=m-1;
        }else{
            return m;
        }
    }
    return b;


}