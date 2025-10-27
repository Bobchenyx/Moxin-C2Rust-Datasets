int maxProfit(int* prices, int pricesSize){
    int maxprofit = 0;
    int profit = 0;
    int i,j;
        for (i = 0; i < pricesSize - 1; i++) {
            for (j = i + 1; j < pricesSize; j++) {
                    profit = prices[j] - prices[i];
                    if (profit > maxprofit)
                        maxprofit = profit;
            }
        }
    return maxprofit;
}