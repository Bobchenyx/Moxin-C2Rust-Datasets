int maxProfit(int* prices, int pricesSize){
    if(pricesSize < 2)
    {
        return 0;
    }

    int max_results = 0;

    for(int i = 1; i < pricesSize; i++)
    {
        if(prices[i] > prices[i - 1])
        {
            max_results += prices[i] - prices[i - 1];
        }
    }

    return max_results;
}