int maxProfit(int *prices, int pricesSize)
{
    int buy;
    int sell;

    if (pricesSize <= 1) {
        return 0;
    }

    buy = prices[0]; //初始买入
    int profit;
    int index;
    profit = 0;
    for (index = 1; index < pricesSize; index++) {
        if (prices[index] < prices[index - 1]) { //转折位置
            /* code */
            sell = prices[index - 1];
            profit += (sell - buy);
            buy = prices[index];
        }
    }

    sell = prices[index - 1];
    if (sell > buy) { //最后一次可能没有转折位置了，如果可以交易就直接交易
        profit += (sell - buy);
    }

    return profit;
}