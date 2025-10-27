int maxProfit(int* prices, int pricesSize){
    int i, min_price = INT_MAX, max_profit = 0;
    for(i = 0;i < pricesSize;i ++){
        max_profit = (prices[i] - min_price > max_profit ? prices[i] - min_price : max_profit);
        min_price = (min_price > prices[i] ? prices[i] : min_price);
    }
    return max_profit;
}