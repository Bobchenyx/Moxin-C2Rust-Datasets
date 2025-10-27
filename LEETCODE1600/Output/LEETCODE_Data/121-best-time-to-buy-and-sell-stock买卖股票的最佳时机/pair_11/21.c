int maxProfit(int* prices, int pricesSize){
    int ans=0;
    int cur_min=INT_MAX;

    for(int i=0;i<pricesSize;i++)
    {
        if(prices[i]>cur_min)
        {
            int t=prices[i]-cur_min;
            ans=ans>t?ans:t;
        }
        else if(prices[i]<cur_min)
        {
            cur_min=prices[i];
        }
    }
    return ans;
}