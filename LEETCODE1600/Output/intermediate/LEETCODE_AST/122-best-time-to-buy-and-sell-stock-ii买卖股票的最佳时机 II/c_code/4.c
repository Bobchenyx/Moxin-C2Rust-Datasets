int maxProfit(int* prices, int pricesSize){
    int result=0;
    for(int i=0;i<pricesSize-1;++i)
        result=prices[i+1]-prices[i]>0?result+prices[i+1]-prices[i]:result;
    return result;
}