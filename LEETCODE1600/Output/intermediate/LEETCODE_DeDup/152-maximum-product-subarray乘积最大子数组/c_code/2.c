class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int res = INT_MIN, imax = 1, imin = 1;
        for (int i = 0; i < n; i++)
        {
        	int tmp = imax;
        	imax = max(max(nums[i], imax * nums[i]), imin * nums[i]);
        	imin = min(min(nums[i], tmp * nums[i]), imin * nums[i]);
        	
        	res = max(res, imax);
		}
		
		return res;
    }
};