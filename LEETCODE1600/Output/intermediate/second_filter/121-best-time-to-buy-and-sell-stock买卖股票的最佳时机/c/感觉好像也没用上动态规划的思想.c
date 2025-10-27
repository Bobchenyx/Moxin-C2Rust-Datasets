int maxProfit(int* prices, int pricesSize){
    int min = 9999;
    int max=0;
    int value;
    for(int i=0;i<pricesSize;i++){
        if(prices[i]<=min){
            min = prices[i];
        }
        else{
            value = prices[i]-min;
            if(max<value){
                max = value;
            }
        }
    }
    return max;
}