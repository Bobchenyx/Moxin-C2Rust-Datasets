#define MIN -2147483648
#define MAX 2147483647

int reverse(int x){
    int j, t, i = 0;
    long int tmp = x, sum = 0;
    while(tmp)
    {
        tmp = tmp/10;
        i++;    //计算x的位数
    }
    tmp = x;
    for(j = 1; j <= i; j++)
    {
        t = tmp/(int)(pow(10,j-1)+0.5)%10; //计算x第j位的值
        if(t==0 && j==1)    //第一位为0的情况
            continue;
        sum += t*(long int)(pow(10,i-j)+0.5);
    }
    if(sum<=MAX && sum>=MIN)    //溢出判断
        return sum;
    else
        return 0;
}