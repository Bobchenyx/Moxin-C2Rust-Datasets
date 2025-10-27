int maxProfit(int* prices, int pricesSize){
    int i;
    int diff;
    int sum = 0;
    int result = 0;

    pricesSize--;

    for (i = 0; i < pricesSize; i++) {
        diff = prices[i + 1] - prices[i];
        sum = (sum + diff < 0) ? 0 : sum + diff;
        result = (sum > result) ? sum : result;
    }

    return result;
}