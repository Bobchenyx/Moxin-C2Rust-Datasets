int numWays(int n)
{
    if(n < 2)
        return 1; 
    int first = 1;     
    int second = 1;
    for(int i = 2; i <= n; ++i)   //从第二层台阶开始到第n层，就不止一种方法了
    {
        int thrid = first + second;    //thrid 是方法数
        first = second;              //用迭代递归都行
        second = thrid;
        second %= 1000000007;     //因为太多会整形溢出，按照题意取了余
    }
    return second;    //返回总数
}