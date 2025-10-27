int maxProfit(int* prices, int pricesSize) {
	int buy = -1, sale = -1, pre_buy = 0, pre_sale = 1;
	int time = 1, profit = 0;
	while (time < pricesSize) {
		if (prices[pre_sale] > prices[pre_buy]) {
			sale = pre_sale;
			buy = pre_buy;
			pre_buy = time;
			pre_sale = pre_buy + 1;
			profit += prices[sale] - prices[buy];
		}
		else {
			pre_buy = time;
			pre_sale = pre_buy + 1;
		}
		time++;
	}
	return profit;
}