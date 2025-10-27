int reverse(int x){
    int n;
    long new_num;
    new_num=0;
    while(x!=0)
    {   
        n=x%10;
        new_num=n+new_num*10;
        x=x/10;
    }
    if((int)new_num!=new_num)
        return 0;
    else
        return (int)new_num;

}