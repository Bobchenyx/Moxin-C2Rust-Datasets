int reverse(int x){
    long ret=0;
    while(x!=0){
        ret=ret*10 + x%10;
        x=x/10;
    }
    if((int)ret != ret)
    {
        return 0;
    }
    else return (int)ret;
}