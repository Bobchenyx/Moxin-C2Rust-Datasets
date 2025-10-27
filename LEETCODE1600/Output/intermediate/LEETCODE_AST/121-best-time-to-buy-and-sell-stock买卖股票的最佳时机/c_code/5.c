int maxProfit(int* prices, int pricesSize)
{
    int i, j, max = 0;
    for(i = 0; i < pricesSize; i++){
        for(j = 0; j < i; j++){
            if(prices[j] < prices[i] && prices[i] - prices[j] > max){
                max = prices[i] - prices[j];
            }
        }
    }
    return max;
}