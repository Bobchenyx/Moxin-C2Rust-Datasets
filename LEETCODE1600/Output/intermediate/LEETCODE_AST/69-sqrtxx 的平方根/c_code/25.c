int mySqrt(int x){
    long i;
    if(x <= 1){
        return x;
    }
    for(i=0;i<x;i++){
        if((i*i) == x){
            return i;
        }
        if((i+1)*(i+1)>x){
            return i;
            
        }
    }
    return i;
}