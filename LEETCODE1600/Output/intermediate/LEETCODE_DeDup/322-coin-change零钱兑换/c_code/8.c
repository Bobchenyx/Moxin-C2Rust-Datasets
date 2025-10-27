for (k = 0; k < coinsSize; k++) {
		if (amount < coins[k]) {
			continue;
		}
		subAns = Dfs(coins, coinsSize, amount - coins[k]);
		if (subAns != -1) {
			tmp = MIN(tmp, subAns);
		}
	}
	if (tmp == INT_MAX) {
		return g_mem[amount] = -1;
	}