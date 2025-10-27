int maxProfit(int* prices, int pricesSize){
    int i=0,j;
    int profit=0;
    
    while(i<pricesSize-1)
    {
        j=i;
        while(i<pricesSize-1&&prices[i]<prices[i+1])//寻找递增子序列
        {
            i++;
        }//此时k为卖出的最好时机
        profit=profit+(prices[i]-prices[j]);
        i++;
    }
    return profit;
}