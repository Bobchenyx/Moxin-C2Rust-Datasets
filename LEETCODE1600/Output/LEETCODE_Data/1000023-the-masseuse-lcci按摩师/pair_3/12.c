class Solution {
public:
    int massage(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        else if(size == 1)
            return nums[0];
        vector<int> dp(size,0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i = 2; i < size; i++)
        {
            int max = 0;
            for(int j = 0; j < i-1; j++)
                max = dp[j]>max?dp[j]:max;
            dp[i] = max+nums[i];
        }
        return *max_element(dp.begin(),dp.end());
    }
};