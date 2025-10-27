class Solution {
public:
    int min = 99999999;

    int coinChange(vector<int>& coins, int amount) {

        int len = coins.size() - 1;
        sort(coins, 0, len);

        dfs(coins, len, amount, 0);
        
        return min == 99999999 ? -1 : min;
    }

    void dfs(vector<int>& coins, int len, int amount, int n)
    {
        if(amount == 0)
        {
            min = min > n ? n : min;
            return ;
        }

        if(len == -1)
            return ;
        
        int num = amount / coins[len];
        
        for(int i = num; i > -1 && n + i < min; i--)
            dfs(coins, len - 1, amount - (i * coins[len]), n + i);
    }

    void sort(vector<int>& coins, int left, int right)
    {
        if(left >= right)
            return ;
        int i = left, j = left, temp;

        for(;i < right; i++)
            if(coins[i] <= coins[right])
            {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
                j++;
            }
        temp = coins[j];
        coins[j] = coins[right];
        coins[right] = temp;

        sort(coins, left, j - 1);
        sort(coins, j + 1, right);
    }
};