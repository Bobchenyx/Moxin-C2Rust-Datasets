int maxProfit(int* prices, int pricesSize){
    if (pricesSize<=1)
        return 0;
    int *min=malloc(sizeof(int)*pricesSize),best=0;
    min[0] = prices[0];
    for (int i=1;i<pricesSize;i++){
        if (min[i-1]>prices[i])
            min[i] = prices[i];
        else
            min[i] = min[i-1];
        if (best<(prices[i]-min[i-1]))
            best = prices[i] - min[i-1];
    }
    return best;
}