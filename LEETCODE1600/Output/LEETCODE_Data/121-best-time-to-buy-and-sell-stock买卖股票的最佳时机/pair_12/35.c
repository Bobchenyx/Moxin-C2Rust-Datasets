int maxProfit(int* prices, int pricesSize){

    int minBuy = 0;
    int maxPro = 0;

    if(prices == NULL
        || pricesSize == 0)
    {
        return 0;
    }

    for(int j=0; j<pricesSize; j++)
    {
        minBuy = prices[j];
        for(int i = j; i <pricesSize; i++)
        {
            if(maxPro < (prices[i] - minBuy))
                maxPro = prices[i] - minBuy;
            
        }

    }

    return maxPro;
}