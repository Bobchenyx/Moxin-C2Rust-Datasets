#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
	int *stack;
	int stkLen;
	int i;
	int result;
	
	stack = (int*)calloc(pricesSize, sizeof(int));
	stkLen = 0;
	result = 0;
	
	for (i = 0; i < pricesSize; i++) {
		if ((stkLen == 0) || (prices[i] >= prices[stack[stkLen - 1]])) {
			stack[stkLen++] = i;			
			continue;
		}
		
		if (stkLen > 1) {
			result += prices[stack[stkLen - 1]] - prices[stack[0]];
		}
		stkLen = 0;
		stack[stkLen++] = i;
	}
	if (stkLen > 1) {
		result += prices[stack[stkLen - 1]] - prices[stack[0]];
	}
	return result;
}