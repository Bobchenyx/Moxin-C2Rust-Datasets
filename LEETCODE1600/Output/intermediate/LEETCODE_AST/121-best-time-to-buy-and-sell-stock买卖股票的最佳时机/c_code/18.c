int maxProfit(int* prices, int pricesSize){
    if(prices==NULL||pricesSize==0) return 0;
    int minprice=prices[0],pro=0;
	for(int i=1;i<pricesSize;i++){
		prices[i]-minprice>pro ? pro=prices[i]-minprice:(NULL);
		prices[i]<minprice ? minprice=prices[i]:(NULL);
	} 
	return pro;	
}