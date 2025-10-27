python3 []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        last, profit = 0, 0
        for i in range(len(prices)-1):
            last = max(0, last + prices[i+1] - prices[i])
            profit = max(profit, last)
        return profit