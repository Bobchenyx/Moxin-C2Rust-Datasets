int maxProfit(int* prices, int pricesSize){
    int maxprofit=0;int lastday=0;int sub=0;int i=0;
	while(i<pricesSize){
		int j=i+1,lastday=i;
		while(j<pricesSize){
			if(prices[i]<prices[j]&&prices[j]>prices[lastday]){
				lastday=j;
			}else{
				if(prices[lastday]-prices[i]<=0){
					sub=0;
				}else{
					sub=prices[lastday]-prices[i];
				}
				maxprofit+=sub;
				break;
			}
		}
		i=j;
	}
	return maxprofit;
}