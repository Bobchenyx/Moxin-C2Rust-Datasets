int maxProfit(int* prices, int pricesSize){
    int maxProfit = 0, j = 1;
    for(int i = 0; i < pricesSize && j < pricesSize; i++){
        if(prices[j] - prices[i] > 0){
             maxProfit += prices[j] - prices[i];
        }
        j++;
    }
    return maxProfit;
}