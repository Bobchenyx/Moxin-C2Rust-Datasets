int maxProfit(int* prices, int pricesSize){
    int i;
    int temp=0;
    int profit=0;
    for(i=0;i<pricesSize-1;i++)
    {
        temp=prices[i+1]-prices[i];
        if(temp>0)
        {
            profit+=temp;
        }
    }
    return profit;
}