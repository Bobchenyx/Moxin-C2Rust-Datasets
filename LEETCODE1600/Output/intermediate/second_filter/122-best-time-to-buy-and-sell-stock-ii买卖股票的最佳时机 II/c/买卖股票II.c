int maxProfit(int* prices, int pricesSize){
    if(pricesSize<2) return 0;
int i=0;
    for(int j=1;j<pricesSize;j++)
    {
        if (prices[j]>prices[j-1])
            i=i+prices[j]-prices[j-1];
    }
    return i;
}