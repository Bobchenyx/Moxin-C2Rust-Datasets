int maxProfit(int* prices, int pricesSize){
    if(pricesSize==0||pricesSize==1)return 0;
    int buy=prices[0],sell=prices[1];
    int price=0;
    for(int i=1;i<pricesSize-1;i++){
        price=(sell-buy)>price?sell-buy:price;
        if(buy>prices[i]){
            buy=prices[i];
            sell=prices[i+1];
        }
        if(sell<prices[i+1])sell=prices[i+1];
    }
    price=(sell-buy)>price?sell-buy:price;
    return price;
}