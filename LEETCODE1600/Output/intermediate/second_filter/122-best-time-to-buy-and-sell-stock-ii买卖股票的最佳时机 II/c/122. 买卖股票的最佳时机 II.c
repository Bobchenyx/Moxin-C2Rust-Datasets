int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize <= 1)
    {
        return 0;
    }
    int ret = 0;
    for(int i = 0; i < (pricesSize-1); i++)
    {
        if((prices[i+1]-prices[i])>0)
            ret += (prices[i+1]-prices[i]);
    }
    return ret;
}