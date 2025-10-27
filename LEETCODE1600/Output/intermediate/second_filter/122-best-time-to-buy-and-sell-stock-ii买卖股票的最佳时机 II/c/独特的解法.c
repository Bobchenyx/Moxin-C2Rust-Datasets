int maxProfit(int* prices, int pricesSize){

    if(pricesSize==0)return 0;

    int l=prices[0];
    int h=prices[0];
    int sum=0;
    for(int i=0;i<pricesSize;i++)
    {
        if(prices[i]>h) //上升时,h自己上升;
            h=prices[i];
        if(prices[i]<h) //下落时,l和h一起下落;当l和h一起下落时,代表到了谷峰,计算此时的差值;
        {
            int d=h-l;  //计算谷峰和谷底差值;
            sum+=d;

            l=prices[i];
            h=prices[i];
        }
    }
    int d=h-l;
    sum+=d;
    return sum;

}