int maxProfit(int* prices, int pricesSize){
    #if 0
    int i , j, temp, max = 0;
    for (i = 0; i < pricesSize; i++){
        for (j = i + 1; j < pricesSize; j++) {
            temp = prices[j] - prices[i];
            max = max > temp ? max : temp;
        }
    }
    return max;
    #endif

    int i, maxpro = 0, min;
    
    if(pricesSize == 0)
        return 0;
    
    min = prices[0];
    for (i = 1; i < pricesSize; i++){
        maxpro = maxpro > (prices[i] - min) ? maxpro : (prices[i] - min);
        min = min < prices[i] ? min : prices[i];
    }

    return maxpro;
}