int reverse(int x){
    long rs =0;
    for(; x; rs = 10*rs + x%10, x=x/10);
    return rs>2147483647||rs<-2147483648?0:rs;

}