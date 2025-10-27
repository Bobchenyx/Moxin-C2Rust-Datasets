int maxProfit(int* prices, int pricesSize)
{
    int i, j;
    int buyPrice, sellPrice;
    int sum  = 0;
    int haveBuyFlag = 0;
    if(pricesSize <= 1) return 0;
    for(i = 0; i < pricesSize-1; i++)
    {
        if(prices[i+1] > prices[i] && haveBuyFlag == 0)
        {
            haveBuyFlag = 1;
            buyPrice = prices[i];
        }
        else if(prices[i+1] <= prices[i])
        {
            if(haveBuyFlag)
            {
                sellPrice = prices[i];
                sum += (sellPrice - buyPrice);
                haveBuyFlag = 0;
            }
        }
    }
    if(i == pricesSize-1 && haveBuyFlag)
    {
        sum += (prices[i]-buyPrice);
    }
    return sum;
}