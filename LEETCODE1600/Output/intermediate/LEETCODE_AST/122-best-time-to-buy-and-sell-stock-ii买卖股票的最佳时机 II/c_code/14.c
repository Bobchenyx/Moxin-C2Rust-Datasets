int maxProfit(int* prices, int pricesSize){
    int shouyi = 0;
    int i = 0;
    for(;i < pricesSize-1;i++){
        if(prices[i] < prices[i+1])
            shouyi = shouyi + prices[i+1] - prices[i];
    }
    return shouyi;
}