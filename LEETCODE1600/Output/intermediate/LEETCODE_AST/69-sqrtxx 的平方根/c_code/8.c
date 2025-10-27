int mySqrt(int x){
    long i;
    for(i = 0;;i++){
        if(i*i > x)
            return i-1;
        if(i*i== x)
            return i;
    }
}