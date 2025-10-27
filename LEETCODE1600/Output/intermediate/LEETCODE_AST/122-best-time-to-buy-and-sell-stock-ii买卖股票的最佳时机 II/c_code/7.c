int maxProfit(int* prices, int pricesSize){
	int sum = 0;
	int i, j;
	for(i = 0, j = 1; j <= pricesSize; j++){
	    if(j == pricesSize || prices[j] < prices[j-1]){
		    sum += prices[j-1] - prices[i];
		    i = j;
	    }
    }
    return sum;
}