int maxProfit(int* prices, int pricesSize){
    if(pricesSize<2)
        return 0;
    //if sold on day i, should bought on day[0,i-1]
    int Lowest=prices[0];
    int prof=0;
    for(int i=1;i<pricesSize;i++)
    {
        prof=((prices[i]-Lowest)>prof)?(prices[i]-Lowest):prof;
        if(prices[i]<Lowest)
        Lowest=prices[i];

    }
    return prof;
}