int maxProfit(int* prices, int pricesSize){
    if (pricesSize==0)
        return 0;
    int buy=0,sell=0;
    int profit=0;
    for(sell=0;sell<pricesSize;sell++)
    {
        if(prices[buy]>prices[sell])
            buy=sell;
        if(profit<prices[sell]-prices[buy])
            profit=prices[sell]-prices[buy];
    }
    return profit;
}