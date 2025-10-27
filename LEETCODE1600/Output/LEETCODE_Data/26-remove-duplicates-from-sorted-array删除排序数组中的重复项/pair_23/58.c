class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size==0)
            return 0;
        int ans = 0;;
        for (int i = 1; i < size; ++i)
        {
            if (nums[i] == nums[ans])
                continue;
            else
            {
                ++ans;
                nums[ans] = nums[i];
            }
                
        }
        return ans+1;
    }
};