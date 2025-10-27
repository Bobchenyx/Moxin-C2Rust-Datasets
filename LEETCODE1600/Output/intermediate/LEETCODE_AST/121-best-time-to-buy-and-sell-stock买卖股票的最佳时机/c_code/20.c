int maxProfit(int* prices, int pricesSize){
    int max_profit = 0;

    for (int i = 1; i < pricesSize; ++i) {
        for (int j = i + 1; j < pricesSize; ++j) {
            max_profit = max_profit > prices[j] - prices[i] ? max_profit : prices[j] - prices[i];
        }
    }
    return max_profit;
}