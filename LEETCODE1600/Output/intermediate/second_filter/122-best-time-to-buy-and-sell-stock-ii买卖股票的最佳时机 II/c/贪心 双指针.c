int maxProfit(int* prices, int pricesSize){
	int ret = 0;
	if (pricesSize < 2){
		return ret;
	}
	int *top = prices, *tail = top+1;
	while (tail <= prices + pricesSize - 1){
		if (*tail < *top){
			top = tail;
			tail++;
		}
		else if (*top<*tail){
			if (tail == prices + pricesSize - 1){
				ret += *tail - *top;
				return ret;
			}
			else if (*tail>*(tail + 1)){
				ret += *tail - *top;
				top = tail + 1;
				tail = top + 1;
			}
			else{
				tail++;
			}
		}
		else{
			tail++;
		}
	}
	return ret;
}