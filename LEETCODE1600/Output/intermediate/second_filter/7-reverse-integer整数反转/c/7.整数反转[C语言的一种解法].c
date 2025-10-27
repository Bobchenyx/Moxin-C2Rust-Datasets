#include <math.h>
//计算并返回一个整数的位数
int numbit(long num)
{
	int n;
	for (n = 1; (num /= 10) != 0; n++)	{	}
	return n;
}
int reverse(int x){
    int n, i, po;   //n表示整数的位数，po用作指数，i为计数器
    int bit[15] = {0};  //存储整数拆开的每一位
    int result = 0;
    long long temp = 0; //存储可能超过int范围的值
    n = numbit(x);
    po = n - 1;
    for (i = 0; i < n; i++, po--)   //将x的每一位拆开，存入bit数组中
    {
        bit[i] = x / (int)pow(10.0, po);
        bit[i] %= 10;
    }
    
    for (i = 0; i < n; i++)         //将每一位乘以10的i次方相加，得到反转的结果
    {
        temp += (long long)(bit[i] * pow(10.0, i));
        if (temp > (long long)pow(2.0, 31) || temp < -1 - (long long)pow(2.0,31)) //溢出
            return 0;
    }
    result = (int)temp;
    return result;
}