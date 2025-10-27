int maxProfit(int* prices, int pricesSize){
    int i=0,j=1,min=0,max=0;
    int result=0;
    for(;i < pricesSize && j < pricesSize;i++,j++){
        while(prices[i]>prices[j] && j < pricesSize){
            i++;
            j++;
            if(j==pricesSize)
                return result;
        }
        min=prices[i];
        while(prices[i]<prices[j] && j < pricesSize){
            i++;
            j++;
            if(j==pricesSize)
                break;
        }
        max=prices[i];
        result=result+max-min;
    }
    return result;
}