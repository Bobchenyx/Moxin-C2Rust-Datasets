int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize == 0) return 0;

    int *f=(int*)malloc(pricesSize*sizeof(int));
    (void)memset(f, 0, pricesSize*sizeof(int));

    int i;
    int curmin = prices[0];
    int max = 0;
    for (i=1; i<pricesSize; i++) {
        curmin = fmin(curmin, prices[i]);

        if (prices[i] < prices[i-1]) {
            f[i] = f[i-1];
        }
        else {
            max = fmax(max, prices[i] - curmin);
            f[i] = max;
        }
    }

    return max;
}