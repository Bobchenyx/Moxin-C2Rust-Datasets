int reverse(int x){
    int flag = 0;
    long int rever=0;
    long int x1=x;
    if(x < 0){
        flag = 1;
        x1 = 0-x1;
    } 
    while(x1>=10)
    {
        rever=rever*10+(x1%10);
        x1=x1/10;
    }
    rever = rever*10+x1;
    if(flag == 1)
    {
        rever=0-rever;
    }
    int i;
    long int max=1;
    for(i=0;i<31;i++)
    {
        max=max*2;
    }
    if(rever > max-1 ||rever <-max) return 0;
    return (int)rever;
}