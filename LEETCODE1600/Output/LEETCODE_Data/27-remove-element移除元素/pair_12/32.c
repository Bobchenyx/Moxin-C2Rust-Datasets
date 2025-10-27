class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 官方题解1 + C++版本 + 优化部分语句
        int loc = 0;
        for (int i=0; i<nums.size(); ++i)
            if (nums[i] != val)
                nums[loc++] = nums[i];
        return loc;
    }
};