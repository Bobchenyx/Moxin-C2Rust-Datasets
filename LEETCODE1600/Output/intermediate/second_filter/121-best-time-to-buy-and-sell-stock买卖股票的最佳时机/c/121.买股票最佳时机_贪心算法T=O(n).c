int maxProfit(int* prices, int pricesSize){
    if(pricesSize <= 0)
        return 0;

    int profit = 0;
    int min = prices[0];
    for(int i = 0; i < pricesSize; i++)
    {
        if(prices[i] < min) //贪心思想，不断更新最小值，期待后面还有大boss
        {
            min = prices[i];
        }   
        else if(profit < (prices[i] - min)) //更新最大收益
            profit = (prices[i] - min);
    }
    return profit;
}