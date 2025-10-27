#define MAX(a,b) (a>b?a:b)
int maxProfit(int* prices, int pricesSize){
    if(pricesSize<=1) return 0;
    int min = prices[0];
    int maxPro = 0;
    for(int i=1;i<pricesSize;i++){
        if(prices[i]>min) maxPro=MAX(maxPro,prices[i]-min);
        else min = prices[i]; 
    }
    return maxPro;
}