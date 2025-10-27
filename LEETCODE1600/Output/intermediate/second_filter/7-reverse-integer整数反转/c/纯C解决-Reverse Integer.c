#define max pow(2,31)-1
#define min (-1)*pow(2,31)
int reverse(int x) {
    long t=x;
    long temp=0;
    while(t)
    {
        temp = 10*temp + (t%10);
        t=t/10;
    }
    if(temp>max||temp<min)//溢出
        return 0;
    return temp;
}