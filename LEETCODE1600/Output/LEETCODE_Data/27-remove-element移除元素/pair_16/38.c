class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
            while(nums[j] == val && i < j) {
                --j;
            }
            while(nums[i] != val && i < j) {
                ++i;
            }
            nums[i] = nums[j--];
        }
        if(i == 0 && nums[i] == val) {
            return 0;
        }
        return i + 1;
    }
};