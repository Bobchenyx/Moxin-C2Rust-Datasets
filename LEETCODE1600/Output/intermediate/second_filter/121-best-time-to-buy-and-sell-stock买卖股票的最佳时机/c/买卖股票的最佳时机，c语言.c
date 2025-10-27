int maxProfit(int* prices, int pricesSize){
    if(pricesSize<2){
        return 0;
    }
    int buy=prices[0],result=0;
    for(int i=1;i<pricesSize;i++){
        if(result<prices[i]-buy){
            result = prices[i]-buy;
        }
        if(buy>prices[i]){
            buy = prices[i];
        }
    }
    return result;
}