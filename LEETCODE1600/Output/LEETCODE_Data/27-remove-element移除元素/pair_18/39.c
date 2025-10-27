class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = nums.size();
        for (auto i = nums.begin(); i < nums.end(); ++i) {
            if (*i == val) {
                i = nums.erase(i);
                --res;
                --i;
            }
        }
        return res;
    }
};