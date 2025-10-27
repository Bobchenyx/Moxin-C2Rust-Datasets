int reverse(int x){
    long count=0;
    while(x!=0){
        count=count*10+x%10;
        x=x/10;
    }
    return count>2147483647||count<-2147483648?0:count;
}