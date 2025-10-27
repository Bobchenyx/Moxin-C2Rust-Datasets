int maxProfit(int* prices, int pricesSize){
    if(pricesSize<2){
        return 0;
    }
    int buyprice=prices[0],result=0;
    for(int i=1;i<pricesSize;i++){
        if(prices[i]<=buyprice){
            buyprice = prices[i];
        }else{
            result += prices[i]-buyprice;
            buyprice = prices[i];
        }
    }
    return result;
}