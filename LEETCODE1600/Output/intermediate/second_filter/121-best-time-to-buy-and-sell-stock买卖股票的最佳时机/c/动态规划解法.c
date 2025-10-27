#define max(a,b) a>b?a:b
int maxProfit(int* prices, int pricesSize){
     if(prices==NULL||pricesSize==0)
        return 0;
    int dp[pricesSize];
    for(int i=0;i<pricesSize;i++)
       dp[i]=0;
    int min_price=prices[0];
    int max_dp=0;
    for(int i=1;i<pricesSize;i++)
    {
        dp[i]=max((prices[i]-min_price),dp[i-1]);
        if(dp[i]>max_dp)
           max_dp=dp[i];

        if(prices[i]<min_price)
            min_price=prices[i];   //更新当前最小价格
    }
    return max_dp;
}